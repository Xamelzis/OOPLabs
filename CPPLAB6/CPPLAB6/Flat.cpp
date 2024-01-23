#include <iostream>
#include <list>
using namespace std;



class Flat {
public:
    int roomCount;
    float area;
    int floor;
    string district;

    Flat(int rooms, float area, int floor, std::string district) : roomCount(rooms), area(area), floor(floor), district(district) {}
};