#include <iostream>
#include <list>
#include "locale.h"
#include "ExchangeSystem.cpp"
using namespace std;





int main() {
    setlocale(LC_ALL, "Russian");
    ExchangeSystem system;

    int choice;
    do {
        cout << "Меню:" << std::endl;
        cout << "1. Ввод заявки на обмен" << std::endl;
        cout << "2. Поиск подходящего варианта обмена" << std::endl;
        cout << "3. Вывод всей картотеки" << std::endl;
        cout << "0. Выход" << std::endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int rooms1, rooms2, floor1, floor2;
            float area1, area2;
            string district1, district2;

            cout << "Введите данные требуемой квартиры (кол-во комнат, площадь, этаж, район): ";
            cin >> rooms1 >> area1 >> floor1 >> district1;
            cout << "Введите данные имеющейся квартиры (кол-во комнат, площадь, этаж, район): ";
            cin >> rooms2 >> area2 >> floor2 >> district2;

            Flat desiredFlat(rooms1, area1, floor1, district1);
            Flat ownedFlat(rooms2, area2, floor2, district2);
            ExchangeRequest request(desiredFlat, ownedFlat);
            system.addExchangeRequest(request);
            break;
        }
        case 2:
            int ownedRoomCount; float ownedArea; int ownedFloor;
            cout << "Введите данные имеющейся квартиры (кол-во комнат, площадь, этаж): ";
            cin >> ownedRoomCount >> ownedArea >> ownedFloor;
            system.findMatchingExchange(ownedRoomCount, ownedArea, ownedFloor);
            break;
        case 3:
            system.displayAllExchangeRequests();
            break;
        case 0:
            cout << "Выход из программы." << std::endl;
            break;
        default:
            cout << "Некорректный выбор. Попробуйте снова." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}