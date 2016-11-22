#ifndef __ROBOTMODEL_H
#define __ROBOTMODEL_H
#include <iostream>
#include "RobotPart.h"


class Robotmodel{
public:
	Robotmodel();//MY
	Robotmodel(string fname, int mnum, double pri);
	void set_name(string fname);
	void set_price(double pri);
	void set_modelNum(int mnum);
	void add_part(Robotpart part);

	string get_name();
	double get_price();
	int get_modelNum();
	vector<Robotpart*>* get_robotParts(); //GS-updated to vector of pointers

	double partCost();
	double maxSpeed();

	string toSave();	//MY 3am

private:
	string name;
	int modelNum;
	double price;
	vector<Robotpart*> robotparts;          //GS-changed to vector of pointers to make derived classes work
};

#endif // __ROBOTMODEL_H
