#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>
#include "BloomFilter.h"

// This abstract class defines an interface for executing commands on a BloomFilter.
class Command {

public:
    // Pure virtual function to execute a command.
    virtual void execute(BloomFilter& filter, const std::string& url) const = 0;

    // Destructor
    virtual ~Command() = default;
};

#endif