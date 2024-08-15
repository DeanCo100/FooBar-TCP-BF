#ifndef INPUT_CHECK_H
#define INPUT_CHECK_H


#include <string>

// Abstract base class for input checking
class InputCheck{

    public:
    // Returns true if the input is valid, false otherwise
    virtual bool checkInput(const std::string& input) const = 0;

    // Ensures proper destruction of derived classes
    virtual ~InputCheck() = default;
};

#endif