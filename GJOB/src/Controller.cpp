#include <iostream>
#include <string.h>
#include "RobotPart.h"
#include "Customer.h"
#include "SalesAssoc.h"
#include "Order.h"
#include "Shop.h"
#include "RobotModel.h"

using namespace std;

void viewModels(Shop GJOB){
    cout << "Models: \n";
    unsigned int i = 0;
    vector<Robotmodel>* models = GJOB.GetRobotModels();
    int ma = (*GJOB.GetRobotModels()).size();
    cout << (*models)[0].get_name();
    for(i = 0; i < (*GJOB.GetRobotModels()).size(); i++){
        cout << (*models)[i].get_name() << "\t\t" << (*models)[i].get_modelNum()<< endl;
    }
}

int create_robotmodel(Shop GJOB){
    string tempname;
    int tempnum;
    double tempprice;

    cout << "Enter the name, model number, and then the price: " << endl;
    cin >> tempname >> tempnum >> tempprice;

    Robotmodel temp = Robotmodel(tempname, tempnum, tempprice);
    int input = 0;
    while(input!=6){
        cout<<"Choose what to add: \n\n"
            <<"1. Arm\n2. Battery\n3. Torso\n4. Head\n5. Motor\n6. Finished" << endl;
        cin >> input;
        if(input == 1){
            Arm temparm = Arm();
            string tname;
            string tdesc;
            int tpnum;
            double tprice;
            double tweight;

            cout << "Enter the Arm name, part number, price, weight, and description\n\n";
            cin >> tname>> tpnum>> tprice>>tweight>> tdesc;
            temparm.set_arm_name(tname);
            temparm.set_arm_description(tdesc);
            temparm.set_arm_partNum(tpnum);
            temparm.set_arm_price(tprice);
            temparm.set_arm_weight(tweight);
            temp.add_part(temparm);
        }
        if(input == 2){
            Battery tempbat = Battery();
            string tname;
            string tdesc;
            int tpnum;
            double tprice;
            double tweight;

            cout << "Enter the Battery name, part number, price, weight, and description\n\n";
            cin >> tname>> tpnum>> tprice>> tweight>> tdesc;
            tempbat.set_battery_name(tname);
            tempbat.set_battery_description(tdesc);
            tempbat.set_battery_partNum(tpnum);
            tempbat.set_battery_price(tprice);
            tempbat.set_battery_weight(tweight);
            temp.add_part(tempbat);
        }
        if(input==3){
            Torso temptor = Torso();
            string tname;
            string tdesc;
            int tpnum;
            double tprice;
            double tweight;

            cout << "Enter the Torso name, part number, price, weight, and description\n\n";
            cin >> tname>> tpnum>> tprice>> tweight>> tdesc;
            temptor.set_torso_name(tname);
            temptor.set_torso_description(tdesc);
            temptor.set_torso_partNum(tpnum);
            temptor.set_torso_price(tprice);
            temptor.set_torso_weight(tweight);
            temp.add_part(temptor);
        }
        if(input==4){
            Head temphea = Head();
            string tname;
            string tdesc;
            int tpnum;
            double tprice;
            double tweight;

            cout << "Enter the Head name, part number, price, weight, and description\n\n";
            cin >> tname>> tpnum>> tprice>> tweight>> tdesc;
            temphea.set_head_name(tname);
            temphea.set_head_description(tdesc);
            temphea.set_head_partNum(tpnum);
            temphea.set_head_price(tprice);
            temphea.set_head_weight(tweight);
            temp.add_part(temphea);
        }
        if(input==5){
            Motor tempmot = Motor();
            string tname;
            string tdesc;
            int tpnum;
            double tprice;
            double tweight;

            cout << "Enter the Motor name, part number, price, weight, and description\n\n";
            cin >> tname>> tpnum>> tprice>> tweight>> tdesc;
            tempmot.set_motor_name(tname);
            tempmot.set_motor_description(tdesc);
            tempmot.set_motor_partNum(tpnum);
            tempmot.set_motor_price(tprice);
            tempmot.set_motor_weight(tweight);
            temp.add_part(tempmot);
        }
    }

    GJOB.AddRobotModel(temp);
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

int menu_create(Shop GJOB){
    int input = 0;
    while(input!=3){
        cout << "Choose an Option: \n\n"
             << "1. Order\n"
             << "2. Robot Model\n3. Return to Main Menu\n"
             << endl;
        cin >> input;
        if(input == 1){
            Customer_Order(GJOB);
        }
        if(input == 2){
            create_robotmodel(GJOB);
        }
    }
    return 0;
}

int Report_SA(Shop GJOB, string aSalesAssoc){
    unsigned int i = 0;
    double total = 0;
    for(; i < (GJOB.GetOrders())->size(); i++){
        string temp = (*GJOB.GetOrders())[i].GetSalesAssoc().GetName();
        if(temp.compare(aSalesAssoc) == 0){
            cout << ((*GJOB.GetOrders())[i]).toString() << endl;
            total += ((*GJOB.GetOrders())[i]).totalPrice();
        }
    }
    cout << "The total is: " << total;
    return 1; //yay
}

int Report_BC(Shop GJOB, string aCustomer){
    unsigned int i = 0;
    double total = 0;
    for(; i < (GJOB.GetOrders())->size(); i++){
        string temp = (*GJOB.GetOrders())[i].GetCustomer().GetName();
        if(temp.compare(aCustomer) == 0){
            cout << endl << ((*GJOB.GetOrders())[i]).toString() << endl;
            total += ((*GJOB.GetOrders())[i]).totalPrice();
        }
    }
    cout << "The total is: " << total;
    return 1; //yay
}

int menu_report(Shop GJOB){
    int input = 0;
    while (input!=5){
        cout << "Choose an option\n\n"
             << "1. Customer\n2. Sales Associate\n3. Robot Model\n"
             << "5. Return to Main Menu" << endl;
        cin >> input;

    if(input == 1){
        cout << "Enter the customers name: " << endl;
        string aCustomer;
        cin >> (aCustomer);
        Report_BC(GJOB, aCustomer);
        }
    if(input == 2){
        cout << "Enter the Associate's name: " << endl;
        string aSalesAssoc;
        cin >> aSalesAssoc;
        Report_SA(GJOB, aSalesAssoc);
        }
    if(input == 3){
        viewModels(GJOB);
        }
    }
    return 0;
}


int menu(Shop GJOB){
    int input = 0;
    while(input !=9){
        cout << "Choose an Option: \n\n"
             << "1. Create\n2. Report\n9. Quit\n\n"
             << endl;
        cin >> input;

        if(input == 1){
            menu_create(GJOB);
        }
        if(input == 2){
            menu_report(GJOB);
        }
    }
    return 0;
}

int main(){
    Shop GJOB = Shop();

    menu(GJOB);

    //todo
    return 0;
}
