#ifndef __ROBOTPART_H
#define __ROBOTPART_H
#include <iostream>
#include <vector>

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

class Arm : Robotpart{
public:
    Arm(string sname, int pnum, double wei, double pr, string desc, PartType ptype)
        : Robotpart(sname, pnum, wei, pr, desc, ptype){}

    int powerCost(int speed);

};

class Battery : Robotpart{
public:
    Battery(string sname, int pnum, double wei, double pr, string desc, PartType ptype, double ene, double maxp)
        : Robotpart(sname, pnum, wei, pr, desc, ptype), energy(ene), maxPow(maxp){}

    double get_energy();
    double get_maxpower();

private:
    double energy;
    double maxPow;
};

class Head : Robotpart{
public:
    Head(string sname, int pnum, double wei, double pr, string desc, PartType ptype)
        : Robotpart(sname, pnum, wei, pr, desc, ptype){}
};

class Motor: Robotpart{
public:
    Motor(string sname, int pnum, double wei, double pr, string desc, PartType ptype, int maxS)
        : Robotpart(sname, pnum, wei, pr, desc, ptype), maxSpeed(maxS){}

    int get_maxS();

private:
    int maxSpeed;
};


class Torso : Robotpart{
public:
    Torso(string sname, int pnum, double wei, double pr, string desc, PartType ptype, int batS)
        : Robotpart(sname, pnum, wei, pr, desc, ptype), batterySlots(batS){}
private:
    int batterySlots;
    Head head;
    vector<Arm> arms;
    Motor motor;
    vector<Battery> batteries;
};


#endif // __ROBOTPART_H
