#ifndef DUP_REMOVE_VEC_H
#define DUP_REMOVE_VEC_H

#include <vector>
#include <algorithm>

// This class responsible for removing duplicates from a vector of integers
class DupRemoveVec {
public:
    // Function to remove duplicates from a vector of integers
    std::vector<int> removeDuplicates(const std::vector<int>& inputVector) const;
};
#endif