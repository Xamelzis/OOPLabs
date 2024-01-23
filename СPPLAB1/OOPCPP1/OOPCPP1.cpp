#include <iostream>
#include "vector.cpp"
using namespace std;

int main() {
    int start_index, end_index;
    cout << "Введите начальный индекс массива: ";
    cin >> start_index;
    cout << "Введите конечный индекс массива: ";
    cin >> end_index;

    Vector vector1(start_index, end_index);
    Vector vector2(start_index, end_index);

    for (int i = start_index; i <= end_index; i++) {
        int value;
        cout << "Введите значение для элемента с индексом " << i << ": ";
        cin >> value;
        vector1[i] = value;
    }

    for (int i = start_index; i <= end_index; i++) {
        int value;
        cout << "Введите значение для элемента с индексом " << i << ": ";
        cin >> value;
        vector2[i] = value;
    }

    int choice;
    cout << "Меню:" << endl;
    cout << "1. Сложение массивов" << endl;
    cout << "2. Вычитание массивов" << endl;
    cout << "3. Умножение массива на скаляр" << endl;
    cout << "4. Деление массива на скаляр" << endl;
    cout << "5. Вывод элемента массива по индексу" << endl;
    cout << "6. Вывод всего массива" << endl;
    cout << "Выберите пункт меню: ";
    cin >> choice;

    try {
        switch (choice) {
        case 1: {
            Vector result = vector1 + vector2;
            cout << "Результат сложения массивов: ";
            result.printAll();
            break;
        }
        case 2: {
            Vector result = vector1 - vector2;
            cout << "Результат вычитания массивов: ";
            result.printAll();
            break;
        }
        case 3: {
            int scalar;
            cout << "Введите скаляр: ";
            cin >> scalar;
            Vector result = vector1 * scalar;
            cout << "Результат умножения массива на скаляр: ";
            result.printAll();
            break;
        }
        case 4: {
            int scalar;
            cout << "Введите скаляр: ";
            cin >> scalar;
            Vector result = vector1 / scalar;
            cout << "Результат деления массива на скаляр: ";
            result.printAll();
            break;
        }
        case 5: {
            int index;
            cout << "Введите индекс элемента: ";
            cin >> index;
            vector1.printElement(index);
            break;
        }
        case 6: {
            cout << "Массив: ";
            vector1.printAll();
            break;
        }
        default:
            cout << "Некорректный выбор меню" << endl;
        }
    }
    catch (const std::exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}