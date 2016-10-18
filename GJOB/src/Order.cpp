#include "Order.h"

using namespace std;

//constructors
Order::Order(int aOrderNum, string aDate, Customer aCustomer, SalesAssoc aSalesAssoc, RobotModel aRobotModel, Status aStatus) {
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
int Order::GetNum{
    return orderNum;
}
void Order::SetDate(Date aDate){
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

/*todo after RobotModel implementation
void Order::SetRobotModel(){

}
RobotModel Order::GetRobotModel(){

}
*/
void Order::SetStatus(Status aStatus){
    status = aStatus;
}
Status Order::GetStatus(){
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
    return 0;//todo
}
