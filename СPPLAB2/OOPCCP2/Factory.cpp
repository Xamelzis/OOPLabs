#include <iostream>
#include <string>
#include "DecString.cpp"
#include "SymbString.cpp"
#include "Factory.h"
#include "DecString.h"
#include "SymbString.h"


class Factory {
public:
    static SymbString* createSymbString(const std::string& id, const std::string& value) {
        return new SymbString(id, value);
    }

    static DecString* createDecString(const std::string& id, int value) {
        return new DecString(id, value);
    }

    static void deleteSymbString(SymbString* symbString) {
        delete symbString;
    }

    static void deleteDecString(DecString* decString) {
        delete decString;
    }
};