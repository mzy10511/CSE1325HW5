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

void Arm::set_arm_name(string fname){
	name = fname;
}
void Arm::set_arm_description(string desc){
	descript = desc;
}
void Arm::set_arm_partNum(int numb){
	partNum = numb;
}
void Arm::set_arm_price(double pri){
	price = pri;
}
void Arm::set_arm_weight(double wei){
	weight = wei;
}

double Battery::get_energy(){
	return energy;
}


void Battery::set_battery_name(string fname){
	name = fname;
}
void Battery::set_battery_description(string desc){
	descript = desc;
}
void Battery::set_battery_partNum(int numb){
	partNum = numb;
}
void Battery::set_battery_price(double pri){
	price = pri;
}
void Battery::set_battery_weight(double wei){
	weight = wei;
}

double Battery::get_maxpower(){
	return maxPow;
}

int Motor::get_maxS(){
	return maxSpeed;
}

void Motor::set_motor_name(string fname){
	name = fname;
}
void Motor::set_motor_description(string desc){
	descript = desc;
}
void Motor::set_motor_partNum(int numb){
	partNum = numb;
}
void Motor::set_motor_price(double pri){
	price = pri;
}
void Motor::set_motor_weight(double wei){
	weight = wei;
}


//GS-forgot to add this before - new update
void Head::set_head_name(string fname){
	name = fname;
}
void Head::set_head_description(string desc){
	descript = desc;
}
void Head::set_head_partNum(int numb){
	partNum = numb;
}
void Head::set_head_price(double pri){
	price = pri;
}
void Head::set_head_weight(double wei){
	weight = wei;
}
//GS-endof new update

void Torso::set_torso_name(string fname){
	name = fname;
}
void Torso::set_torso_description(string desc){
	descript = desc;
}
void Torso::set_torso_partNum(int numb){
	partNum = numb;
}
void Torso::set_torso_price(double pri){
	price = pri;
}
void Torso::set_torso_weight(double wei){
	weight = wei;
}

void Torso::set_arms(int numb){
	arms = numb;
}
void Torso::set_batteryslots(int numb){
	batterySlots = numb;
}
