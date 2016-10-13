#ifndef SALESASSOC_H
#define SALESASSOC_H
#include <iostream>
#include <vector>

using namespace std;

class SalesAssoc
{
    public:
        //constructors
        SalesAssoc(string name, int employeeNum);
        //SalesAssoc(String name, int employeeNum, Order orders[]); todo after orders implementaiton

        //Setters and Getters
        void SetName(String name);
        string GetName();
        void SetNum(int employeeNum);
        int GetNum();
        void SetOrders();//todo after orders implementation
        //Order GetOrders();

    protected:
        string name;
        int employeeNum;
        //Order[] orders;
};

#endif // SALESASSOC_H
