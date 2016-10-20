#include <iostream>
#include <string.h>
#include <time.h>
#include "RobotPart.h"
#include "RobotModel.h"
#include "Customer.h"
#include "SalesAssoc.h"
#include "Order.h"
#include "Shop.h"

using namespace std;

int create_RobotModel(Shop GJOB){
    return 0;
}

int menu_create(Shop GJOB){
    int input = 0;
    while(input!=6){
        cout << "Choose an Option: \n\n"
             << "1. Order\n2. Customer\n3. Sale Associate\n"
             << "4. Robot Model\n 5. Robot Component\n6. Return to Main Menu\n"
             << endl;
        cin >> input;

        if(input == 4){
            create_RobotModel(GJOB);
        }
    }
    return 0;
}


int menu(Shop GJOB){
    int input = 0;
    while(input !=9){
        cout << "Choose an Option: \n\n"
             << "1. Create\n2. Report\n3. Save\n9. Quit\n\n"
             << endl;
        cin >> input;

        if(input == 1){
            menu_create(GJOB);
        }
    }
    return 0;
}

int Customer_Order(Shop GJOB){
    //Get customer
    cout << endl << "Hello, Beloved Customer, what is your name?(First-Last):" << endl;
    string custName;
    cin >> custName;
    //get wallet
    cout << endl << "Greetings, " << custName << ". What is your budget?" << endl;
    double custWallet;
    cin >> custWallet;
    //get model number
    cout << endl << "Enter a Model Number:" << endl;
    int modelNum;
    cin >> modelNum;
    //search for Model
    unsigned int i = 0;
    Robotmodel temp;
    for(;i < GJOB.GetRobotModels()->size(); i++){
        if((*GJOB.GetRobotModels())[i].get_modelNum() == modelNum){
            temp = (*GJOB.GetRobotModels())[i];
            break;
        }
        else{
            cout << endl << "Invalid Model Number" << endl;
            return 0; //fail
        }
    }
    //get model count
    cout << endl << "How Many?:" << endl;
    int orderNum;
    cin >> orderNum;
    //get sale date
    cout << endl << "Enter the date (MM/DD/YYYY):" << endl;
    string date;
    cin >> date;
    //get employee
    cout << endl << "Who helped you today? (First-Last):" << endl;
    string employeeName;
    cin >> employeeName;
    //get customer number
    cout << endl << employeeName << ", please enter the customer's number." << endl;
    int custNum;
    cin >> custNum;
    //get employee id
    cout << endl << employeeName << ", please enter your employee number to confirm order." << endl;
    int employeeNum;
    cin >> employeeNum;

    cout << endl << "Enter a status:" << endl;
    string status;
    cin >> status;
    GJOB.AddOrder(Order(orderNum, date, Customer(custName, custNum, custWallet), SalesAssoc(employeeName, employeeNum), temp, status));

    return 1;//yay
}

int Report_SA(Shop GJOB, SalesAssoc aSalesAssoc){
    unsigned int i = 0;
    double total = 0;
    for(; i < (GJOB.GetOrders())->size(); i++){
        string temp = (*GJOB.GetOrders())[i].GetSalesAssoc().GetName();
        if(temp.compare(aSalesAssoc.GetName()) == 0){
            cout << ((*GJOB.GetOrders())[i]).toString() << endl;
            total += ((*GJOB.GetOrders())[i]).totalPrice();
        }
    }
    cout << "The total is: " << total;
    return 1; //yay
}

int Report_BC(Shop GJOB, Customer aCustomer){
    unsigned int i = 0;
    double total = 0;
    for(; i < (GJOB.GetOrders())->size(); i++){
        string temp = (*GJOB.GetOrders())[i].GetCustomer().GetName();
        if(temp.compare(aCustomer.GetName()) == 0){
            cout << endl << ((*GJOB.GetOrders())[i]).toString() << endl;
            total += ((*GJOB.GetOrders())[i]).totalPrice();
        }
    }
    cout << "The total is: " << total;
    return 1; //yay
}

int main(){
    Shop GJOB = Shop();
    SalesAssoc aSA = SalesAssoc("1-1", 90210);//test
    Customer aBC = Customer("Customer Juan", 1, 1);//test
    GJOB.AddOrder(Order(1, "11/11/1111", aBC, aSA, Robotmodel(), "1"));//test
    //Customer_Order(GJOB);
    Report_SA(GJOB, aSA);//test
    Report_BC(GJOB, aBC);
    //GJOB.GetCustomers();
    //todo
    return 0;
}
