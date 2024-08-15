#ifndef LIST_EXISTENCE_CHECKER_H
#define LIST_EXISTENCE_CHECKER_H

#include <iostream>
#include <list>
#include <algorithm>

// Class for checking existence of a value in a list
class ListExistenceChecker {

public:
    // Returns true if the value exists, false otherwise
    bool isExist(const std::list<std::string>& container, const std::string& value) const;
};

#endif