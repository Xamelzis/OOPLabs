#include <iostream>
#include <stdexcept>
using namespace std;

class Vector {
public:
    int* data;
    int start_index;
    int end_index;
    Vector(int start, int end) : start_index(start), end_index(end) {
        int size = end - start + 1;
        data = new int[size];
    }

    ~Vector() {
        delete[] data;
    }

    int& operator[](int index) {
        if (index < start_index || index > end_index) {
            throw std::out_of_range("Index out of range");
        }
        return data[index - start_index];
    }

    Vector operator+(const Vector& other) const {
        if (start_index != other.start_index || end_index != other.end_index) {
            throw std::invalid_argument("Arrays must have the same indices");
        }
        Vector result(start_index, end_index);
        for (int i = start_index; i <= end_index; i++) {
            result[i] = data[i - start_index] + other.data[i - start_index];
        }
        return result;
    }

    Vector operator-(const Vector& other) const {
        if (start_index != other.start_index || end_index != other.end_index) {
            throw invalid_argument("Arrays must have the same indices");
        }
        Vector result(start_index, end_index);
        for (int i = start_index; i <= end_index; i++) {
            result[i] = data[i - start_index] - other.data[i - start_index];
        }
        return result;
    }

    Vector operator*(int scalar) const {
        Vector result(start_index, end_index);
        for (int i = start_index; i <= end_index; i++) {
            result[i] = data[i - start_index] * scalar;
        }
        return result;
    }

    Vector operator/(int scalar) const {
        Vector result(start_index, end_index);
        for (int i = start_index; i <= end_index; i++) {
            result[i] = data[i - start_index] / scalar;
        }
        return result;
    }

    void printElement(int index) const {
        if (index < start_index || index > end_index) {
            throw out_of_range("Index out of range");
        }
        cout << data[index - start_index] << endl;
    }

    void printAll() const {
        for (int i = start_index; i <= end_index; i++) {
            cout << data[i - start_index] << " ";
        }
        cout << endl;
    }
};