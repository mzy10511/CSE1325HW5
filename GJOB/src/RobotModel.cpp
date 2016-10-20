#include "RobotModel.h"

Robotmodel::Robotmodel(){}
Robotmodel::Robotmodel(string fname, int mnum, double pri){
    set_name(fname);
    set_price(pri);
    set_modelNum(mnum);

}

void Robotmodel::set_name(string fname){
    name = fname;
}

void Robotmodel::set_price(double pri){
    price = pri;
}
void Robotmodel::set_modelNum(int mnum){
    modelNum = mnum;
}
void Robotmodel::add_part(Robotpart part){
    robotparts.push_back(&part);
}

string Robotmodel::get_name(){
    return name;
}

double Robotmodel::get_price(){
    return price;
}

int Robotmodel::get_modelNum(){
    return modelNum;
}

vector<Robotpart*>* Robotmodel::get_robotParts(){//GS-updated
    return &robotparts;
}

double Robotmodel::partCost(){
    unsigned int i;
    double cost = 0;
    for(i = 0; i < (robotparts).size(); i++){
        cost += (robotparts)[i]->get_price();
    }
    return cost;
}
double Robotmodel::maxSpeed(){
    return 0;
}
