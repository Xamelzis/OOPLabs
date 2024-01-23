#include <iostream>
#include <stdexcept>

template <typename T>
class B {
public:
    T data;
    B* left;
    B* right;

    B(T val) : data(val), left(nullptr), right(nullptr) {}
};