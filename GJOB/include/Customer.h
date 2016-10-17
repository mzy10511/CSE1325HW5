#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <vector>

using namespace std;

class Customer
{
    public:
        //constructors
        Customer(string name, int customerNum, double wallet, Order orders[]);

        //getters and setters
        void SetName(String name);
        string GetName();
        void SetNum(int customerNum);
        int GetNum();
        void SetWallet(double wallet);
        double GetWallet();
        void SetOrders();
        Order[] GetOrders();

    protected:
        string name;
        int customerNum;
        double wallet;
        Order orders[];
};

#endif // CUSTOMER_H
