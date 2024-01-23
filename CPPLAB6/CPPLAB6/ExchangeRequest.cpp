#include <iostream>
#include <list>
#include <string>
#include "Flat.cpp"
using namespace std;

class ExchangeRequest {
public:
    Flat desiredFlat;
    Flat ownedFlat;

    ExchangeRequest(Flat desired, Flat owned) : desiredFlat(desired), ownedFlat(owned) {}
};