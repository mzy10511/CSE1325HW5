#include "SalesAssoc.h"

using namespace std;

//constructors
SalesAssoc::SalesAssoc(string name, int employeeNum) {
    SetName(name);
    SetNum(employeeNum);
}

/*todo after Orders implementation
SalesAssoc::SalesAssoc(String name, int employeeNum, Order orders[]) {
    //todo
}
*/

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

/*todo after orders implementation
void SalesAssoc::SetOrders(Order aOrders[]) {
    orders = aOrders;
}
Order SalesAssoc::GetOrders() {
    return orders;
}
*/
