#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>

using namespace std;

class Customer
{
    public:
        //constructors
        Customer();
        Customer(string name, int customerNum, double wallet);
        //Customer(string name, int customerNum, double wallet, Order orders[]);

        //getters and setters
        void SetName(string name);
        string GetName();
        void SetNum(int customerNum);
        int GetNum();
        void SetWallet(double wallet);
        double GetWallet();
        //void SetOrders();
        //Order[] GetOrders();

    protected:
        string name;
        int customerNum;
        double wallet;
        //Order orders[];
};

#endif // CUSTOMER_H
