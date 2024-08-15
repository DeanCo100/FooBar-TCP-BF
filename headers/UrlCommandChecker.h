#ifndef URL_COMMAND_CHECKER_H
#define URL_COMMAND_CHECKER_H
#include "InputCheck.h" // Include the base class header file
#include <iostream>
#include <sstream>
#include <map>

#define HASH1 1
#define HASH2 2

// Class for checking URL commands based on InputCheck interface
class UrlCommandChecker : public InputCheck {

public:
    // Destructor
    virtual ~UrlCommandChecker() = default;

    // Checks whether a given string is valid for input (overrides base class function)
    bool checkInput(const std::string& input) const override;

    // Checks whether the istring stream object holds a valid command
    bool isValidCommand(std::istringstream& iss) const;

    // Checks whether the istring stream object holds a valid URL
    bool isValidURL(std::istringstream& iss) const;
};

#endif