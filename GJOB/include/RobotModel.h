#ifndef __ROBOTMODEL_H
#define __ROBOTMODEL_H
#include <iostream>
#include "RobotPart.h"


class Robotmodel{
public:
    Robotmodel();
    Robotmodel(string fname, int mnum, double pri);
    void set_name(string fname);
    void set_price(double pri);
    void set_modelNum(int mnum);
    void add_part(Robotpart part);

    string get_name();
    double get_price();
    int get_modelNum();
    vector<Robotpart>* get_robotParts();

    double partCost();
    double maxSpeed();

private:
    string name;
    int modelNum;
    double price;
    vector<Robotpart> robotparts;
};

#endif // __ROBOTMODEL_H
