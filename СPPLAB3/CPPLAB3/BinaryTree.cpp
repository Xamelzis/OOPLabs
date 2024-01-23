#include <iostream>
#include <stdexcept>
#include "B.cpp"
using namespace std;

template <typename T>
class BinaryTree {
private:
    B<T>* root; // ������ ��������� ������

public:
    BinaryTree() : root(nullptr) {}

    // ����� ��� ���������� �������� � �������� ������
    void addElement(const T element) {
        try {
            root = addElementRecursive(root, element);
        }
        catch (exception e) {
            cerr << "������: " << e.what() << endl;
            throw;
        }
    }

    // ����������� ����� ��� ���������� �������� � �������� ������
    B<T>* addElementRecursive(B<T>* node, const T element) {
        if (node == nullptr) {
            try {
                return new B<T>(element); // �������� ������ ����
            }
            catch (exception e) {
                cerr << "������ �������� ����: " << e.what() << endl;
                throw;
            }
        }
        else if (element < node->data) {
            node->left = addElementRecursive(node->left, element);
        }
        else if (element > node->data) {
            node->right = addElementRecursive(node->right, element);
        }
        else {
            throw runtime_error("������� ��� ���������� � �������� ������");
        }

        return node;
    }

    // ������� ��� ������ ������
    void printTree() {
        printTreeRecursive(root);
    }

    // ����������� ������� ��� ������ ������
    void printTreeRecursive(B<T>* node) {
        if (node != nullptr) {
            printTreeRecursive(node->left);
            cout << node->data << " ";
            printTreeRecursive(node->right);
        }
    }
};
