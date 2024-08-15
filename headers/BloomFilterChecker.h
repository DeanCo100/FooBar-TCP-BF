#ifndef BLOOM_FILTER_CHECKER_H
#define BLOOM_FILTER_CHECKER_H

#include "InputCheck.h"
#include <iostream>
#include <sstream>
#include <tuple>
#include <set>
#include <vector>

#define HASH1 1
#define HASH2 2

class BloomFilterChecker : public InputCheck {
public:

    // Destructor
    virtual ~BloomFilterChecker() = default;

    // Checks whether a given string is valid for input
    bool checkInput(const std::string& input) const override;

    // Checks if the istringstream object holds a value that can actually be array size
    bool validateArraySize(std::istringstream& iss) const;

    // Checks whether the stream holds correct hash functions
    bool isValidHashFunctions(std::istringstream& iss) const;
};

#endif