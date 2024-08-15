#include "ProgramFlow.h"
#include <iostream>
#include <sstream>
#include <tuple>
#include <map>

// Sets up the Bloom filter with user input.
void ProgramFlow::bloomFilterSetup(){
    int arraySize;
    std::vector<int> hashFunctions;
    BloomFilterChecker BloomFilterCheck;
    DupRemoveVec DuplicateRemover;

    // Loop until valid input is provided.
    while (true) {
        std::string setupInput;
        std::getline(std::cin, setupInput);
        // Check if the input is valid.
        if (BloomFilterCheck.checkInput(setupInput)) {
            // If the input is valid, extract arraySize and hashFunctions.
            std::istringstream iss(setupInput);
            iss >> arraySize;
            int hashFunction;
            // Add to the vector storing the values for hash functions.
            while (iss >> hashFunction) {
                hashFunctions.push_back(hashFunction);
            }
            // If the input is valid, break out of the loop
            break;
        }
    }
        // Removes duplicates
        std::vector<int> HashFunctionsNoDup = DuplicateRemover.removeDuplicates(hashFunctions);
        // Creates the bloom filter.
        this->bloomFilter = new ::BloomFilter(arraySize,HashFunctionsNoDup);
}

// Destructor.
ProgramFlow::~ProgramFlow() {
    // Release the dynamically allocated BloomFilter.
    delete bloomFilter;
}

// Runs the main program.
void ProgramFlow::run(){
    bloomFilterSetup();
    flow();
}

// Manages the flow of the program.
void ProgramFlow::flow(){
    //setting up the commands map
    UrlCommandChecker UrlChecker;
    std::map<int, Command*> CommandMap;
    AddUrlCommand Command1;
    LookUpCommand Command2;
    CommandMap[1] = &Command1;
    CommandMap[2] = &Command2;
    std::string flowInput;
    while(true){
        // Extracting the input
        std::getline(std::cin, flowInput);
        if(UrlChecker.checkInput(flowInput)){
            std::istringstream iss(flowInput);
            int operation;
            std::string url;
            iss >> operation;
            iss>>url;
            CommandMap[operation]->execute(*bloomFilter,url);
        }
    }

}
