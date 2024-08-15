#ifndef ADD_URL_COMMAND_H
#define ADD_URL_COMMAND_H
#include "Command.h" // Include the base class header file
#include "BloomFilter.h"
#include <string>

// Class specifically designed for adding a URL to a BloomFilter.
class AddUrlCommand : public Command {
public:

    // Overridden execute method to add a URL to the BloomFilter.
    void execute(BloomFilter& filter, const std::string& url) const override;
};

#endif  