#ifndef LOOK_UP_COMMAND_H
#define LOOK_UP_COMMAND_H

#include "Command.h" // Include the base class header file
#include "BloomFilter.h"
#include <string>

// Concrete command class for looking up a URL in a BloomFilter.
class LookUpCommand : public Command {
public:
    // Overridden execute method to look up a URL in the BloomFilter.
    virtual void execute(BloomFilter& filter, const std::string& url) const override;
};
#endif