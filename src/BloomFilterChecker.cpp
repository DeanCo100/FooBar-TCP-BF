#include "BloomFilterChecker.h"
#include <iostream>
#include <sstream>
#include <tuple>
#include <set>
#include <vector>
#define HASH1 1
#define HASH2 2

// Checks whether a given string is valid for input.
bool BloomFilterChecker::checkInput(const std::string& input) const {
    std::istringstream iss(input);
    // If the array size is not valid or hash functions not valid.
    if ((!validateArraySize(iss)) || (!isValidHashFunctions(iss))) {
        return false;
    } 
    // Check if the stream has reached the end of input.
    if (!iss.eof()) {
        return false;
    }
    // Return true indicating validity.
    else{
        return true;
    }
}

// Checks if the istring stream object holds a value that can actually be array size.
bool BloomFilterChecker::validateArraySize(std::istringstream& iss) const {
int arraySize;
// If array size is equals or less than zero.
if (!(iss >> arraySize) || arraySize <= 0) {
    return false;
}
return true;
}

// Checks if the hash functions are valid to use in the Bloom filter.
bool BloomFilterChecker::isValidHashFunctions(std::istringstream& iss) const {
    int HashFunction;
    // Checking whether the stream is empty
    if(iss.eof()){
        return false;
    }
    // Running on the stream until its empty.
    while (!(iss.eof())) {
        // Check if the value of hashFunction is out of bounds or not 1 or 2.
        if (!(iss >> HashFunction) || (HashFunction != HASH1 && HashFunction != HASH2)) {
            return false;
    }

    // Check if there are more characters in the stream.
    if (iss.peek() == ' ' || iss.peek() == '\n' || iss.peek() == '\r') {
        iss.ignore(); // Ignore the space or newline character
    }
}
return true;
}