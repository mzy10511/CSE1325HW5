#ifndef __ROBOTPART_H
#define __ROBOTPART_H
#include <iostream>
#include <vector>

using namespace std;

enum PartType {arm = 1, battery = 2, torso = 3, head = 4, motor = 5};

class Robotpart{
public:
    Robotpart() {}
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
    Arm(){}

    int powerCost(int speed);
    void set_arm_name(string fname);
    void set_arm_partNum(int numb);
    void set_arm_weight(double wei);
    void set_arm_price(double pri);
    void set_arm_description(string desc);

};

class Battery : Robotpart{
public:
    Battery(){}

    void set_battery_name(string fname);
    void set_battery_partNum(int numb);
    void set_battery_weight(double wei);
    void set_battery_price(double pri);
    void set_battery_description(string desc);

    double get_energy();
    double get_maxpower();

private:
    double energy;
    double maxPow;
};

class Head : Robotpart{
public:
    Head(){}
    void set_head_description(string desc);
    void set_head_price(double pri);
    void set_head_weight(double wei);
    void set_head_partNum(int numb);
    void set_head_name(string fname);

};

class Motor: Robotpart{
public:
    Motor(){}
    void set_motor_name(string fname);
    void set_motor_partNum(int numb);
    void set_motor_weight(double wei);
    void set_motor_price(double pri);
    void set_motor_description(string desc);

    int get_maxS();

private:
    int maxSpeed;
};


class Torso : Robotpart{
public:
    Torso(){}
    void set_torso_name(string fname);
    void set_torso_partNum(int numb);
    void set_torso_weight(double wei);
    void set_torso_price(double pri);
    void set_torso_description(string desc);

    void set_batteryslots(int numb);
    void set_arms(int numb);

private:
    int batterySlots;
    int arms;

};


#endif // __ROBOTPART_H
