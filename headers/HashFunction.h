#include <cstddef>
#include <string>
#ifndef HASH_FUNCTIONS_H
#define HASH_FUNCTIONS_H

// Hash Function Interface
class HashFunction {
    public:
        // Applies a hash function on a given string
        virtual size_t applyHash(const std::string& value) const = 0;
        // Defining the destructor
        virtual ~HashFunction() = default;
};
#endif