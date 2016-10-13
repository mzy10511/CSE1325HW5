#include <iostream>
class Arm : Robotpart{
public:
    Arm(){}
    int powerCost(int speed){return speed * 55;}
};

