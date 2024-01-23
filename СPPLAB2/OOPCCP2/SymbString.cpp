#include "SymbString.h"
#include <iostream>
#include <string>

class SymbString {
private:
    std::string id;
    std::string value;

public:
    SymbString(const std::string& id, const std::string& value) : id(id), value(value) {}

    std::string getId() const {
        return id;
    }

    std::string getValue() const {
        return value;
    }

    void setValue(const std::string& newValue) {
        value = newValue;
    }
};