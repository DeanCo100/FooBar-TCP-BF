// The file of the TCP server:
#include <iostream>
#include <sstream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <thread>
#include "../headers/BloomFilter.h" // Include the BloomFilter header

// Function to handle clients
void handleClient(int client_sock, BloomFilter& bloomFilter) {
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    
    while (true) {
        int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
        if (read_bytes == 0) {
            // connection is closed by client
            break;
        } else if (read_bytes < 0) {
            perror("error receiving from client");
            break;
        } else {
            // Process received data based on the protocol
            std::istringstream iss(std::string(buffer, read_bytes)); // Convert buffer to string and initialize istringstream

            // Split the message by newline characters
            std::string line;
            while (std::getline(iss, line, '\n')) {
                if (line.substr(0, 1) == "1") {
                    // Extracts the URL
                    std::string url = line.substr(2);

                    // Print the URL being added to the Bloom filter for debugging
                    std::cout << "Adding URL to Bloom filter: " << url << std::endl;

                    bloomFilter.insert(url);

                } else if (line.substr(0, 1) == "2") {
                    // Extracts the URL
                    std::string url = line.substr(2);

                    // Print the URL being checked against the Bloom filter for debugging
                    std::cout << "Checking URL in Bloom filter: " << url << std::endl;

                    bool isBlacklisted = bloomFilter.lookup(url);
                    std::string response;
                    // Check for false-positive
                    if (isBlacklisted) {
                        bool isFalsePositive = bloomFilter.isFalsePositive(url);
                        if (isFalsePositive) {
                            response = "false";
                            std::cout << response << std::endl;
                        } else {
                            response = "true";
                            std::cout << response << std::endl;

                        }
                    } else {
                        response = "false";
                        std::cout << response << std::endl;

                    }
                    // false = not blacklisted, true = blacklisted
                    send(client_sock, response.c_str(), response.length(), 0);
                }
            }
        }
    }
    
    close(client_sock); // Close client socket when done
}

// The TCP server function
int main() {
    const int server_port = 5555;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
        return 1;
    }

    struct sockaddr_in sin;
    std::memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    if (bind(sock, (struct sockaddr*)&sin, sizeof(sin)) < 0) {
        perror("error binding socket");
        return 1;
    }

    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
        return 1;
    }

    // Define the size and userInput vector
    const int size = 128; // Size by bytes
    std::vector<int> userInput = {1, 2}; // Vector containing numbers 1 and 2

    // Instantiate BloomFilter object with size and userInput vector
    BloomFilter bloomFilter(size, userInput);


    while (true) {
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr*)&client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
            continue;
        }

        // Create a new thread to handle communication with the client
        std::thread clientThread(handleClient, client_sock, std::ref(bloomFilter));
        clientThread.detach(); // Detach the thread (allow it to run independently)
    }

    close(sock);
    return 0;
}

