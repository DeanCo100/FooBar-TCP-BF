#include "ListExistenceChecker.h"

// Checks if a value exists in a given list.
bool ListExistenceChecker::isExist(const std::list<std::string>& container, const std::string& value) const {
    return std::find(container.begin(), container.end(), value) != container.end();
}