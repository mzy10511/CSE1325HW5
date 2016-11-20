#ifndef SALESASSOC_H
#define SALESASSOC_H
#include <iostream>

using namespace std;

class SalesAssoc
{
    public:
        //constructors
        SalesAssoc();
        SalesAssoc(string name, int employeeNum);

        //Setters and Getters
        void SetName(string name);
        string GetName();
        void SetNum(int employeeNum);
        int GetNum();
        //void SetOrders(Order orders[]);
        //Order[] GetOrders();

    protected:
        string name;
        int employeeNum;
        //Order orders[];
};

#endif // SALESASSOC_H
