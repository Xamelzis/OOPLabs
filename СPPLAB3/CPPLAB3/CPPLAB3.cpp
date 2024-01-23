#include <iostream>
#include <stdexcept>
#include "BinaryTree.cpp"
using namespace std;


int main() {
    try {
        BinaryTree<int> tree; //  шаблон для типа int
        tree.addElement(5);
        tree.addElement(3);
        tree.addElement(7);
        tree.printTree();
    }
    catch (exception e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    try {
        BinaryTree<double> tree; //  шаблон для типа double
        tree.addElement(2.5);
        tree.addElement(1.8);
        tree.addElement(3.7);
        tree.printTree();
    }
    catch (exception e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    try {
        BinaryTree<std::string> tree; //  шаблон для типа std::string
        tree.addElement("apple");
        tree.addElement("banana");
        tree.addElement("orange");
        tree.printTree();
    }
    catch (std::exception e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}

