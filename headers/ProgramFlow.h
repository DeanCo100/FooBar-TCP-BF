#ifndef PROGRAM_FLOW_H
#define PROGRAM_FLOW_H
#include "BloomFilter.h"
#include "BloomFilterChecker.h"
#include "DupRemoveVec.h"
#include "UrlCommandChecker.h"
#include "AddUrlCommand.h"
#include "LookUpCommand.h"
#include <iostream>
#include <sstream>
#include <tuple>
#include <map>

// ProgramFlow class manages the overall flow of the program.
class ProgramFlow {
public:
    // Sets up the Bloom filter with user input.
    void bloomFilterSetup();
    // Runs the main program.
    void run();
    // Manages the flow of the program.
    void flow();
    // Destructor
    ~ProgramFlow();

private:
    BloomFilter* bloomFilter; // Pointer to the BloomFilter instance
};

#endif