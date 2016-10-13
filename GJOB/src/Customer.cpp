#include "Customer.h"

using namespace std;

//constructors
Customer::Customer(string name, int customerNum, double wallet) {
    //todo
}


/*todo after Orders implementation
Customer::Customer(String name, int employeeNum, double wallet, Order orders[]) {
    //todo
}
*/

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

/*todo after orders implementation
void Customer::SetOrders(Order aOrders[]) {
    orders = aOrders;
}
Order Customer::GetOrders() {
    return orders;
}
*/

