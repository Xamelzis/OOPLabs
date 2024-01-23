#include <iostream>
#include <list>
#include "ExchangeRequest.cpp"
using namespace std;


class ExchangeSystem {
private:
    list<ExchangeRequest> exchangeRequests;

public:
    void addExchangeRequest(ExchangeRequest request) {
        exchangeRequests.push_back(request);
    }

    void findMatchingExchange(int desiredRoomCount, float desiredArea, int desiredFloor) {
        for (auto it = exchangeRequests.begin(); it != exchangeRequests.end(); ) {
            if (it->desiredFlat.roomCount == desiredRoomCount &&
                it->desiredFlat.floor == desiredFloor &&
                abs(it->desiredFlat.area - desiredArea) / desiredArea <= 0.1) {
                cout << "Найден подходящий вариант обмена для следующей заявки:" << std::endl;
                displayExchangeRequest(*it);
                it = exchangeRequests.erase(it);
            }
            else {
                ++it;
            }
        }
    }

    void displayAllExchangeRequests() {
        cout << "Все заявки на обмен в системе:" << std::endl;
        for (const auto request : exchangeRequests) {
            displayExchangeRequest(request);
        }
    }

private:
    void displayExchangeRequest(ExchangeRequest request) {
        cout << "Желаемая квартира - Комнаты: " << request.desiredFlat.roomCount
            << ", Площадь: " << request.desiredFlat.area
            << ", Этаж: " << request.desiredFlat.floor
            << ", Район: " << request.desiredFlat.district
            << std::endl;
        cout << "Имеющаяся квартира - Комнаты: " << request.ownedFlat.roomCount
            << ", Площадь: " << request.ownedFlat.area
            << ", Этаж: " << request.ownedFlat.floor
            << ", Район: " << request.ownedFlat.district
            << std::endl;
    }
};
