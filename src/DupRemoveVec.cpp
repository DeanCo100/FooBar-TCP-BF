#include <iostream>
#include <vector>
#include <algorithm>
#include "DupRemoveVec.h"

// Function to remove duplicates from a vector of integers.
std::vector<int> DupRemoveVec::removeDuplicates(const std::vector<int>& inputVector) const {
    std::vector<int> resultVector = inputVector;
    // Remove duplicates using std::unique.
    resultVector.erase(std::unique(resultVector.begin(), resultVector.end()), resultVector.end());
    return resultVector;
}