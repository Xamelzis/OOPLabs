#include <iostream>
#include <string>
#include "DecString.cpp"
#include "SymbString.cpp"
#include "Factory.cpp"



std::string operator-(const SymbString& s1, const SymbString& s2) {
    std::string result = s1.getValue();

    size_t found = result.find(s2.getValue());
    if (found != std::string::npos) {
        result.erase(found, s2.getValue().length());
    }

    return result;
}

int main() {
    SymbString* symbString = Factory::createSymbString("s1", "Hello, World!");
    DecString* decString = Factory::createDecString("d1", 42);

    std::cout << "SymbString ID: " << symbString->getId() << std::endl;
    std::cout << "SymbString Value: " << symbString->getValue() << std::endl;

    std::cout << "DecString ID: " << decString->getId() << std::endl;
    std::cout << "DecString Value: " << decString->getValue() << std::endl;

    std::string result = *symbString - *symbString;
    std::cout << "Result: " << result << std::endl;

    Factory::deleteSymbString(symbString);
    Factory::deleteDecString(decString);

    return 0;
}



