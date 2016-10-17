#ifndef SHOP_H
#define SHOP_H
#include <iostream>
#include <path.h>

using namespace std;

class Shop
{
    public:
        //constructors
        Shop(Order orders[], RobotModel RobotModels[], Customer customers[], SalesAssoc salesAssoc[]);

        //setters and getters
        void SetOrders(Order orders[]);
        Order[] GetOrders();
        void SetRobotModels();//
        RobotModel[] GetRobotModels;//
        void SetCustomers();
        Customer[] GetCustomers();
        void SetSalesAssoc();
        SalesAssoc[] GetSalesAssoc();

        //class methods
        void createRobotModel();
        void newCustomer();
        void placeOrder();
        //void run Report(Report report);
        void saveData(Path aPath);

    protected:
        Order orders[];
        //RobotModel robotModels[];
        Customer customers[];
        SalesAssoc salesAssoc[];
};

#endif // SHOP_H
