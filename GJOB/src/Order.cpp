#include "Order.h"

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
    string temp = " Order Num:" + orderNum;
    string t2 =" Date:" + date + " Customer:" + customer.GetName() + " Sales Associate:" + salesAssoc.GetName() + " Robot Model:" + robotModel.get_name() + " Status:" + status;
    return temp + t2;
}
