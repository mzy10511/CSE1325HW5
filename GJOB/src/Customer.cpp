#include "Customer.h"

using namespace std;

//constructors
Customer::Customer(string aName, int aCustomerNum, double aWallet, Order aOrders[]) {
    //todo
}

//Setters and Getters
void Customer::SetName(string aName) {
    name = aName;
}
string Customer::GetName() {
    return name;
}

void Customer::SetNum(int aCustomerNum) {
    customerNum = aCustomerNum;
}
int Customer::GetNum() {
    return customerNum;
}

void Customer::SetWallet(double aWallet) {
    wallet = aWallet;
}
int Customer::GetWallet() {
    return wallet;
}

void Customer::SetOrders(Order aOrders[]) {
    orders = aOrders;
}
Order[] Customer::GetOrders() {
    return orders;
}


