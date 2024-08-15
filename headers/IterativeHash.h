#ifndef ITERATIVE_HASH_H
#define ITERATIVE_HASH_H

#include "HashFunction.h" // Include the base class header file

// IterativeHash Class - applies basic hash function a given number of times.
class IterativeHash : public HashFunction {
public:
    // Constructor
    IterativeHash(int numOfIter);
    // Apply the hash function
    size_t applyHash(const std::string& value) const override;
private:
    int numOfIter;
};
#endif
