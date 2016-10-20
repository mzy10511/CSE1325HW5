#ifndef ORDER_H
#define ORDER_H
#include "Customer.h"
#include "SalesAssoc.h"
#include <iostream>
#include "RobotModel.h"



using namespace std;

class Order
{
    public:
        //constructors
        Order();
        Order(int orderNum, string date, Customer customer, SalesAssoc salesAssoc, Robotmodel robotmodel, string status);

        //getters and setters
        void SetNum(int orderNum);
        int GetNum();
        void SetDate(string date);
        string GetDate();
        void SetCustomer(Customer customer);
        Customer GetCustomer();
        void SetSalesAssoc(SalesAssoc salesAssoc);
        SalesAssoc GetSalesAssoc();
        void SetRobotModel(Robotmodel robotModel);
        Robotmodel GetRobotModel();
        void SetStatus(string status);
        string GetStatus();

        //class methods
        double robotPrice();
        double calcShipping();
        double calcTax();
        double totalPrice();


    protected:
        int orderNum;
        string date;
        Customer customer;
        SalesAssoc salesAssoc;
        Robotmodel robotModel;
        string status;

};

#endif // ORDER_H
