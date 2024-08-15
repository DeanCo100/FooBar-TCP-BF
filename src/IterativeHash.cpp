#include "IterativeHash.h"
#include <iostream>

// Constructor.
IterativeHash::IterativeHash(int numOfIter):
    numOfIter(numOfIter){
}

// Implementation of abstract method - applyHash.
size_t IterativeHash::applyHash(const std::string& value) const {
    
    // Applying the hash for the first time
    std::hash<std::string> hashFunction;
    size_t oneIterResult = hashFunction(value);
    size_t hashResult = oneIterResult;

    //Iterating on the the result of applying the hash for the first time
    for(int i = 1;i < numOfIter;i++){
        oneIterResult = hashFunction(std::to_string(oneIterResult));
        hashResult = oneIterResult;
    }
    return hashResult;
};