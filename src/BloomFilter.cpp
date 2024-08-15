#include "BloomFilter.h"
#include <iostream>
#include <memory> // Include the memory header for smart pointers
#include <algorithm>
#define HASH1 1
#define HASH2 2

// Bloom filter constructor.
BloomFilter::BloomFilter(int size, const std::vector<int>& userInput)
    : size(size),  userInput(userInput), bitArray(size, false), hashFunctions() {
    // Initialize hash functions.
    addHashFunctions();
}

// Adds hash functions to the hashFunctions vector.
void BloomFilter::addHashFunctions() {
    for (int i : userInput) {
        // Accept only "1" or "2" as hash functions.
        if (i == HASH1) {
            hashFunctions.push_back(std::unique_ptr<HashFunction>(new BasicHash()));
        } else if (i == HASH2) {
            hashFunctions.push_back(std::unique_ptr<HashFunction>(new IterativeHash(HASH2)));
        }
    }
}

// Insertion into bloom filter.
void BloomFilter::insert(const std::string& address) {
    // Iterating over all the hash functions and apply them on given input
    for (const auto& hashFunction : hashFunctions) {
        // Applying the hash and finding the correct index in order to mark.
        size_t hashResult = indexFinder(address, *hashFunction);
        this->bitArray[hashResult] = true;
    }
    // Inserting the url to the url black list
    URList.push_front(address);
}

// Lookup if an address is inside the bloom filter.
bool BloomFilter::lookup(const std::string& address) {
    // Iterating through the vector of hash functions
    for (const auto& hashFunction : hashFunctions) {
        size_t hash = indexFinder(address, *hashFunction);
        if (!bitArray[hash]) {
            return false;
        }
    }
    return true;
}

// Checks if a given URL may result in a false positive in the Bloom filter.
bool BloomFilter::isFalsePositive(const std::string& address) {
    // Checks if the address could be in the bloom filter.
    if (!BloomFilter::lookup(address)) {
        // If false - definitely not false positive.
        return false;
    }

    // Checks whether the URL is actually in the URL blacklist.
    ListExistenceChecker listChecker;
    // Meaning - not exist, then is false positive, and isn't otherwise.
    return !listChecker.isExist(URList, address);
}

// Finds the index in the Bloom filter for a given URL and hash function.
size_t BloomFilter::indexFinder(const std::string& address, HashFunction& hashFunction) {
    return hashFunction.applyHash(address) % this->size;
}