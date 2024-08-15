#include "AddUrlCommand.h"
//#include "../../headers/BloomFilter.h"

// Overridden execute method to add a URL to the BloomFilter.
void AddUrlCommand::execute(BloomFilter& filter, const std::string& url) const  {
    filter.insert(url);
};
