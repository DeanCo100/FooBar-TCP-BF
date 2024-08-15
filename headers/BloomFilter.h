#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

#include "BasicHash.h"
#include "IterativeHash.h"
#include "ListExistenceChecker.h"
#include <vector>
#include <string>
#include <list>
#include <memory>

// BloomFilter class implements a space-efficient data structure for storing URLs
class BloomFilter
{
private:
    int size;
    std::vector<int> userInput;  // Store hash functions
    std::list<std::string> URList; // List of URLs in the bloom filter
    std::vector<bool> bitArray; // The actual bit array representing the filter's state
    std::vector<std::unique_ptr<HashFunction>> hashFunctions; // Smart pointers to hash functions


public:
    //Constructor
    BloomFilter(int size, const std::vector<int>& userInput);

    // Methods

    //  Adds hash functions to the Bloom filter.
    void addHashFunctions();
    // Inserts a string URL into the Bloom filter.
    void insert(const std::string &address);
    // Performs a lookup in the Bloom filter.
    bool lookup(const std::string &address);
    // Checks if a given URL may result in a false positive in the Bloom filter.
    bool isFalsePositive(const std::string &address);
    // Finds the index in the Bloom filter for a given URL and hash function.
    size_t indexFinder(const std::string& address,HashFunction& HashFunction);
};

#endif
