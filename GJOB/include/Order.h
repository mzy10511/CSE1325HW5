#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <vector>

using namespace std;

class Order
{
    public:
        //constructors
        Order(int orderNum, Date date, Customer customer, SalesAssoc salesAssoc);
        //Order(int orderNum, Date date, Customer customer, SalesAssoc salesAssoc, RobotModel robotModel, Status status);

        //getters and setters
        void SetNum(int orderNum);
        int GetNum();
        void SetDate(Date date);
        Date GetDate();
        void SetCustomer(Customer customer);
        Customer GetCustomer();
        void SetSalesAssoc(SalesAssoc salesAssoc);
        SalesAssoc GetSalesAssoc();
        void SetRobotModel();//todo after RobotModel implementation
        //Order GetRobotModel();
        void SetStatus(Status status);
        Status GetStatus();

        //class methods
        double robotPrice();
        double calcShipping();
        double calcTax();
        double totalPrice();


    protected:
        int orderNum;
        Date date;
        Customer customer;
        SalesAssoc salesAssoc;
        //RobotModel robotModel;
        Status status;

};

#endif // ORDER_H
