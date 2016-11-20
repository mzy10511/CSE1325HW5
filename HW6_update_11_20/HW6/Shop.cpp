#include "Shop.h"

using namespace std;

Shop::Shop(){
    //todo
}
Shop::Shop(vector<Order> orders, vector<Robotmodel> robotModels, vector<Customer> customers, vector<SalesAssoc> salesAssocs){
    //ctor
}

void Shop::AddOrder(Order aOrder){
    orders.push_back(aOrder);
}
void Shop::SetOrders(vector<Order> aOrders){
    orders.clear();
    unsigned int i = 0;
    for(;i<aOrders.size()-1; i++){
        AddOrder(aOrders[i]);
    }
}
vector<Order>* Shop::GetOrders(){
    return &orders;
}
void Shop::AddRobotModel(Robotmodel aRobotModel){
    robotModels.push_back(aRobotModel);
}
void Shop::SetRobotModels(vector<Robotmodel> aRobotModels){
    robotModels.clear();
    unsigned int i = 0;
    for(;i<aRobotModels.size()-1; i++){
        AddRobotModel(aRobotModels[i]);
    }
}
vector<Robotmodel>* Shop::GetRobotModels(){
    return &robotModels;
}

void Shop::AddCustomer(Customer aCustomer){
    customers.push_back(aCustomer);
}
void Shop::SetCustomers(vector<Customer> aCustomers){
    customers.clear();
    unsigned int i = 0;
    for(;i<aCustomers.size()-1; i++){
        AddCustomer(aCustomers[i]);
    }
}
vector<Customer>* Shop::GetCustomers(){
    return &customers;
}
void Shop::AddSalesAssoc(SalesAssoc aSalesAssoc){
    salesAssocs.push_back(aSalesAssoc);
}
void Shop::SetSalesAssocs(vector<SalesAssoc> aSalesAssocs){
    salesAssocs.clear();
    unsigned int i = 0;
    for(;i<aSalesAssocs.size()-1; i++){
        AddSalesAssoc(aSalesAssocs[i]);
    }
}
vector<SalesAssoc>* Shop::GetSalesAssoc(){
    return &salesAssocs;
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
//void saveData(Path aPath){
    //todo
//}
