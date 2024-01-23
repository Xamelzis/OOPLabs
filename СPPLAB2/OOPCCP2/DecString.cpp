#include <iostream>
#include <string>
#include "DecString.h"

class DecString {
private:
    std::string id;
    int value;

public:
    DecString(const std::string& id, int value) : id(id), value(value) {}

    std::string getId() const {
        return id;
    }

    int getValue() const {
        return value;
    }

    void setValue(int newValue) {
        value = newValue;
    }
};