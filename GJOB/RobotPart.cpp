#include "RobotPart.h"

using namespace std;

string Robotpart::get_name(){
    return name;
    }

int Robotpart::get_partNum(){
    return partNum;
    }

double Robotpart::get_weight(){
    return weight;
    }

double Robotpart::get_price(){
    return price;
    }

string Robotpart::get_descript(){
    return descript;
    }

int Arm::powerCost(int speed){
    return speed*3.1415;
    }

double Battery::get_energy(){
    return energy;
    }

double Battery::get_maxpower(){
    return maxPow;
    }

int Motor::get_maxS(){
    return maxSpeed;
    }

