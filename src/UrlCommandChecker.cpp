#include "UrlCommandChecker.h"
#include <iostream>
#include <sstream>
#include <map>
#define HASH1 1
#define HASH2 2

// Checks whether a given string follows the desired pattern for a command followed by a URL.
bool UrlCommandChecker::checkInput(const std::string& input) const {
        std::istringstream iss(input);
        // Checking whether the the command is valid and the url.
        return isValidCommand(iss) && isValidURL(iss); 
}

// Checks if the command in the input stream is valid.
bool UrlCommandChecker::isValidCommand(std::istringstream& iss) const {
    int command;

    // Try to extract integer from input stream and skip leading whitespaces. 
    if (!(iss >> std::ws >> command)) {
        return false;
    }
    // Check if there are a leading whitespace after the command.
    if (iss.peek() != EOF && !isspace(iss.peek())) {
        return false;
    }
    // Check if the command integer is valid.
    if (command != HASH1 && command != HASH2) {
        return false;
}
    return true;
}

// Checks if the URL in the input stream is valid.
bool UrlCommandChecker::isValidURL( std::istringstream& iss) const {
    std::string urlString;
    if (!(iss >> urlString)) {
                return false;
            }
    return true;        
};
