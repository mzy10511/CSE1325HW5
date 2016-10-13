#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <vector>

using namespace std;

class Customer
{
    public:
        //constructors
        Customer(string name, int customerNum, double wallet);
        //Customer(string name, int customerNum, double wallet, Order orders[]); todo

        //getters and setters
        void SetName(String name);
        string GetName();
        void SetNum(int customerNum);
        int GetNum();
        void SetWallet(double wallet);
        double GetWallet();
        void SetOrders();//todo after orders implementation
        //Order GetOrders();

    protected:
        string name;
        int customerNum;
        double wallet;
        //Order orders[];
};

#endif // CUSTOMER_H
