#include <iostream>
#include <stdlib.h>
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

int Customer_Order(Shop GJOB, Customer aCustomer, SalesAssoc SalesAssoc){
    cout << endl << "Enter a Model Number:" << endl;
    int modelNum;
    cin >> modelNum;
    cout << endl << "How Many?:" << endl;
    int orderNum;
    cin >> orderNum;
    cout << endl;


    return 0;//fail
}

int main(){
    Shop GJOB = Shop();
    //GJOB.GetCustomers();
    //todo
    return 0;
}
