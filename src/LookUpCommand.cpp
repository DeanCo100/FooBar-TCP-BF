#include "LookUpCommand.h"
#include <iostream>

// Overridden execute method to look up a URL in the BloomFilter.
void LookUpCommand:: execute(BloomFilter& filter, const std::string& url) const {
    bool isExist =filter.lookup(url);
    if(!(isExist)){
        std::cout<<"false\n";
    }
    else if(filter.isFalsePositive(url)){
        std::cout<<"true false\n";
    }
    else{
        std::cout<<"true true\n";
    }

}