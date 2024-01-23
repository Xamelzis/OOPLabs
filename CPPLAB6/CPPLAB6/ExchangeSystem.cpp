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
                cout << "������ ���������� ������� ������ ��� ��������� ������:" << std::endl;
                displayExchangeRequest(*it);
                it = exchangeRequests.erase(it);
            }
            else {
                ++it;
            }
        }
    }

    void displayAllExchangeRequests() {
        cout << "��� ������ �� ����� � �������:" << std::endl;
        for (const auto request : exchangeRequests) {
            displayExchangeRequest(request);
        }
    }

private:
    void displayExchangeRequest(ExchangeRequest request) {
        cout << "�������� �������� - �������: " << request.desiredFlat.roomCount
            << ", �������: " << request.desiredFlat.area
            << ", ����: " << request.desiredFlat.floor
            << ", �����: " << request.desiredFlat.district
            << std::endl;
        cout << "��������� �������� - �������: " << request.ownedFlat.roomCount
            << ", �������: " << request.ownedFlat.area
            << ", ����: " << request.ownedFlat.floor
            << ", �����: " << request.ownedFlat.district
            << std::endl;
    }
};
