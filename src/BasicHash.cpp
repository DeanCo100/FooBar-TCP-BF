#include "BasicHash.h"
#include <functional>
#include <iostream>


// Implementation of abstract method - applyHash
size_t BasicHash::applyHash(const std::string& value) const {
    std::hash<std::string> hashFunction; 
    return hashFunction(value);
}


