#include <iostream>
#include <algorithm>
#include <locale.h>

class TRAIN {
private:
    std::string destination;
    int trainNumber;
    std::string departureTime;

public:
    // Методы доступа к полям
    const std::string& getDestination() const {
        return destination;
    }

    int getTrainNumber() const {
        return trainNumber;
    }

    const std::string& getDepartureTime() const {
        return departureTime;
    }

    // Перегруженные операции извлечения и вставки
    friend std::istream& operator>>(std::istream& in, TRAIN& train) {
        std::cout << "Введите название пункта назначения:\n ";
        in >> train.destination;
        std::cout << "Введите номер поезда: \n";
        in >> train.trainNumber;
        std::cout << "Введите время отправления: \n";
        in >> train.departureTime;
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const TRAIN& train) {
        out << "Пункт назначения: " << train.destination << ", Номер поезда: " << train.trainNumber << ", Время отправления: " << train.departureTime;
        return out;
    }
};



//--------------------------------------------------------------------------------------------//



int main() {
    setlocale(LC_ALL, "Russian");
    // Ввод данных в массив из шести объектов типа TRAIN и сортировка по времени отправления
    TRAIN trains[2];
    for (int i = 0; i < 2; ++i) {
        std::cin >> trains[i];
    }
    std::sort(std::begin(trains), std::end(trains), [](const TRAIN& a, const TRAIN& b) {
        return a.getDepartureTime() < b.getDepartureTime();
        });

    // Вывод информации о поездах, направляющихся в указанный пункт назначения
    std::string inputDestination;
    std::cout << "Введите название пункта назначения для поиска: ";
    std::cin >> inputDestination;
    bool found = false;
    for (const auto& train : trains) {
        if (train.getDestination() == inputDestination) {
            std::cout << train << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "Поездов в указанный пункт назначения не найдено." << std::endl;
    }

    return 0;
}