#ifndef BASIC_HASH_H
#define BASIC_HASH_H

#include "HashFunction.h" // Include the base class header file
#include <string>

// Basic Hash Function Class - h1 
class BasicHash : public HashFunction {
public:
    // Apply the basic hash function on a given string
    size_t applyHash(const std::string& value) const override;
};

#endif
