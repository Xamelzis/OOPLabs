#include <iostream>
#include <stdexcept>
#include "B.cpp"
using namespace std;

template <typename T>
class BinaryTree {
private:
    B<T>* root; // Корень бинарного дерева

public:
    BinaryTree() : root(nullptr) {}

    // Метод для добавления элемента в бинарное дерево
    void addElement(const T element) {
        try {
            root = addElementRecursive(root, element);
        }
        catch (exception e) {
            cerr << "Ошибка: " << e.what() << endl;
            throw;
        }
    }

    // Рекурсивный метод для добавления элемента в бинарное дерево
    B<T>* addElementRecursive(B<T>* node, const T element) {
        if (node == nullptr) {
            try {
                return new B<T>(element); // Создание нового узла
            }
            catch (exception e) {
                cerr << "Ошибка создания узла: " << e.what() << endl;
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
            throw runtime_error("Элемент уже существует в бинарном дереве");
        }

        return node;
    }

    // Функция для вывода дерева
    void printTree() {
        printTreeRecursive(root);
    }

    // Рекурсивная функция для вывода дерева
    void printTreeRecursive(B<T>* node) {
        if (node != nullptr) {
            printTreeRecursive(node->left);
            cout << node->data << " ";
            printTreeRecursive(node->right);
        }
    }
};
