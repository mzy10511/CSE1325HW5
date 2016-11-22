#ifndef SHOP_H
#define SHOP_H
#include <iostream>
#include "Order.h"
#include <vector>
#include "RobotModel.h"


using namespace std;

class Shop
{
public:
	//constructors
	Shop();
	Shop(vector<Order> orders, vector<Robotmodel> robotModels, vector<Customer> customers, vector<SalesAssoc> salesAssocs);

	//setters and getters
	void AddOrder(Order order);
	void SetOrders(vector<Order> aOrders);
	vector<Order> *GetOrders();
	void AddRobotModel(Robotmodel aRobotModel);
	void SetRobotModels(vector<Robotmodel> aRobotModels);
	vector<Robotmodel>* GetRobotModels();
	string get_full_string_models(vector<Robotmodel>* models);//GS
	void AddRobotPart(Robotpart * aRobotPart);			//-----GS
	void SetRobotParts(vector<Robotpart*> aRobotParts); //-----GS
	vector<Robotpart*>* GetRobotParts();				//-----GS
	string get_full_string_parts(vector<Robotpart*>* parts);//-GS
	void AddCustomer(Customer customer);
	void SetCustomers(vector<Customer> aCustomers);
	vector<Customer> *GetCustomers();
	void AddSalesAssoc(SalesAssoc salesAssoc);
	void SetSalesAssocs(vector<SalesAssoc> salesAssocs);
	vector<SalesAssoc> *GetSalesAssoc();

	//class methods
	void createRobotModel();
	void newCustomer();
	void placeOrder();
	//void run Report(Report report);
	void saveData(string aPath);	//my 3am
	void loadData(string aPath);	//my 3am

protected:
	vector<Order> orders;
	vector<Robotmodel> robotModels;
	vector<Robotpart*> robotParts;				//-----GS
	vector<Customer> customers;
	vector<SalesAssoc> salesAssocs;
};

#endif // SHOP_H
