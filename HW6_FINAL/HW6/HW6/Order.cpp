#include "Order.h"
#include <string>
using namespace std;

//constructors
Order::Order(){}
Order::Order(int aOrderNum, string aDate, Customer aCustomer, SalesAssoc aSalesAssoc, Robotmodel aRobotModel, string aStatus) {
	SetNum(aOrderNum);
	SetDate(aDate);
	SetCustomer(aCustomer);
	SetSalesAssoc(aSalesAssoc);
	SetRobotModel(aRobotModel);
	SetStatus(aStatus);
}

//setters and getters
void Order::SetNum(int aOrderNum){
	orderNum = aOrderNum;
}
int Order::GetNum(){
	return orderNum;
}
void Order::SetDate(string aDate){
	date = aDate;
}
string Order::GetDate(){
	return date;
}
void Order::SetCustomer(Customer aCustomer){
	customer = aCustomer;
}
Customer Order::GetCustomer(){
	return customer;
}
void Order::SetSalesAssoc(SalesAssoc aSalesAssoc){
	salesAssoc = aSalesAssoc;
}
SalesAssoc Order::GetSalesAssoc(){
	return salesAssoc;
}

void Order::SetRobotModel(Robotmodel aRobotModel){
	robotModel = aRobotModel;
}
Robotmodel Order::GetRobotModel(){
	return robotModel;
}

void Order::SetStatus(string aStatus){
	status = aStatus;
}
string Order::GetStatus(){
	return status;
}

//class methods
double Order::robotPrice(){
	return 0;//todo
}
double Order::calcShipping(){
	return 0;//todo
}
double Order::calcTax(){
	return 0;//todo
}
double Order::totalPrice(){
	return robotModel.get_price() * orderNum;//todo
}
string Order::toString(){
	string temp = "\nOrder Num:" + to_string(orderNum);
	string t2 = "\nDate:" + date + "\nCustomer:" + customer.GetName() + "\nSales Associate:" + salesAssoc.GetName() + "\nRobot Model:" + robotModel.get_name() + "\nStatus:" + status;
	return (temp + t2);
}
string Order::toSave(){	//my3am
	string temp = "\n" + to_string(orderNum);
	string t2 = "\n" + date + "\n" + customer.GetName() + "\n" + salesAssoc.GetName() + "\n" + robotModel.get_name() + "\n" + status;
	return (temp + t2);
}
