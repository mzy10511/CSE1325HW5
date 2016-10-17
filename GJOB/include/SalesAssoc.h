#ifndef SALESASSOC_H
#define SALESASSOC_H
#include <iostream>

using namespace std;

class SalesAssoc
{
    public:
        //constructors
        SalesAssoc(String name, int employeeNum, Order orders[]);

        //Setters and Getters
        void SetName(String name);
        string GetName();
        void SetNum(int employeeNum);
        int GetNum();
        void SetOrders(Order orders[]);
        Order[] GetOrders();

    protected:
        string name;
        int employeeNum;
        Order orders[];
};

#endif // SALESASSOC_H
