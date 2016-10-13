#ifndef __ROBOTPART_H
#define __ROBOTPART_H
#include <iostream>
#include <vector>
#include "Arm.h"
#include "Battery.h"
#include "Head.h"
#include "Motor.h"
#include "Torso.h"

using namespace std;

enum PartType {arm = 1, battery = 2, torso = 3, head = 4, motor = 5};

class Robotpart{
public:
    Robotpart(string sname, int pnum, double wei, double pr, string desc, PartType ptype)
        : name(sname), partNum(pnum), weight(wei), price(pr), descript(desc), partType(ptype) {}
    virtual string get_name();
    virtual int get_partNum();
    virtual double get_weight();
    virtual double get_price();
    virtual string get_descript();

protected:
    string name;
    int partNum;
    double weight;
    double price;
    string descript;
    PartType partType;

};




#endif // __ROBOTPART_H
