#include "Shop.h"

using namespace std;

Shop::Shop(Order orders[], RobotModel RobotModels[], Customer customers[], SalesAssoc salesAssoc[]){
    //ctor
}

void Shop::SetOrders(Order aOrders[]){
    orders = aOrders;
}
Shop::Order[] GetOrders(){
    return orders;
}
/*
void Shop::SetRobotModels(RobotModels aRobotModels[]){
    robotModels = aRobotModels;
}
RobotModel[] GetRobotModels;//
*/
void Shop::SetCustomers(Customer aCustomers[]){
    customers = aCustomers;
}
Shop::Customer[] GetCustomers(){
    return customers;
}
void Shop::SetSalesAssoc(SalesAssoc aSalesAssoc[]){
    salesAssoc = aSalesAssoc;
}
Shop::SalesAssoc[] GetSalesAssoc(){
    return salesAssoc;
}

//class methods
void createRobotModel(){
    //todo
}
void newCustomer(){
    //todo
}
void placeOrder(){
    //todo
}
//void run Report(Report report){
    //todo
//}
void saveData(Path aPath){
    //todo
}
