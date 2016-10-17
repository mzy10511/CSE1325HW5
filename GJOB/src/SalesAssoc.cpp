#include "SalesAssoc.h"

using namespace std;

//constructors
SalesAssoc::SalesAssoc(string aName, int aEmployeeNum, Order aOrders[]) {
    SetName(aName);
    SetNum(aEmployeeNum);
    SetOrders(aOrders);
}

//Setters and Getters
void SalesAssoc::SetName(string aName) {
    name = aName;
}
string SalesAssoc::GetName() {
    return name;
}

void SalesAssoc::SetNum(int aEmployeeNum) {
    employeeNum = aEmployeeNum;
}
int SalesAssoc::GetNum() {
    return employeeNum;
}

void SalesAssoc::SetOrders(Order aOrders[]) {
    orders = aOrders;
}
Order[] SalesAssoc::GetOrders() {
    return orders;
}

