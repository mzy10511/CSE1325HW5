#include "Shop.h"
#include <string>
#include <fstream> //MY 3am
using namespace std;

Shop::Shop(){
	//todo
}
Shop::Shop(vector<Order> orders, vector<Robotmodel> robotModels, vector<Customer> customers, vector<SalesAssoc> salesAssocs){
	//ctor
}

void Shop::AddOrder(Order aOrder){
	orders.push_back(aOrder);
}
void Shop::SetOrders(vector<Order> aOrders){
	orders.clear();
	unsigned int i = 0;
	for (; i<aOrders.size() - 1; i++){
		AddOrder(aOrders[i]);
	}
}
vector<Order>* Shop::GetOrders(){
	return &orders;
}
void Shop::AddRobotModel(Robotmodel aRobotModel){
	robotModels.push_back(aRobotModel);

}
void Shop::SetRobotModels(vector<Robotmodel> aRobotModels){
	robotModels.clear();
	unsigned int i = 0;
	for (; i<aRobotModels.size() - 1; i++){
		AddRobotModel(aRobotModels[i]);
	}
}
vector<Robotmodel>* Shop::GetRobotModels(){
	return &robotModels;
}

string Shop::get_full_string_models(vector<Robotmodel>* models){
	Robotmodel mm;
	string s = "";
	unsigned int i = 0, j;
	for (; i < models->size(); i++){
		mm = models->at(i);
		s += mm.get_name() + "\n\tModel Number:";
		s += to_string(mm.get_modelNum()) + "\n\tPrice:";
		s += to_string(mm.get_price()) + "\n\tParts:\n\t\t";
		vector<Robotpart*>* rr = mm.get_robotParts();
		Robotpart* pp;
		for (j = 0; j < rr->size(); j++){
			pp = rr->at(i);
			s += pp->get_name() + "\n\t\t";
		}
		s += "\n\n";
	}
	return s;
}

void Shop::AddRobotPart(Robotpart * aRobotPart){			//-----GS
	robotParts.push_back(aRobotPart);
}

void Shop::SetRobotParts(vector<Robotpart*> aRobotParts){	//-----GS
	robotParts.clear();
	unsigned int i = 0;
	for (; i < aRobotParts.size(); i++){
		robotParts.push_back(aRobotParts[i]);
	}
}

vector<Robotpart*>* Shop::GetRobotParts(){					//-----GS
	return &robotParts;
}

string Shop::get_full_string_parts(vector<Robotpart*>* parts){//---GS
	Robotpart* pp;
	string s = "";
	unsigned int i = 0;
	for (; i < parts->size(); i++){
		pp = parts->at(i);
		s += pp->get_name() + "\n\tPart Number:";
		s += to_string(pp->get_partNum()) + "\n\tWeight:";
		s += to_string(pp->get_weight()) + "\n\tPrice:";
		s += to_string(pp->get_price()) + "\n\tDescription:";
		s += pp->get_descript() + "\n\n";
	}
	return s;
}
void Shop::AddCustomer(Customer aCustomer){
	customers.push_back(aCustomer);
}
void Shop::SetCustomers(vector<Customer> aCustomers){
	customers.clear();
	unsigned int i = 0;
	for (; i<aCustomers.size() - 1; i++){
		AddCustomer(aCustomers[i]);
	}
}
vector<Customer>* Shop::GetCustomers(){
	return &customers;
}
void Shop::AddSalesAssoc(SalesAssoc aSalesAssoc){
	salesAssocs.push_back(aSalesAssoc);
}
void Shop::SetSalesAssocs(vector<SalesAssoc> aSalesAssocs){
	salesAssocs.clear();
	unsigned int i = 0;
	for (; i<aSalesAssocs.size() - 1; i++){
		AddSalesAssoc(aSalesAssocs[i]);
	}
}
vector<SalesAssoc>* Shop::GetSalesAssoc(){
	return &salesAssocs;
}

//class methods
void createRobotModel(){
}
void newCustomer(){
	//todo
}
void placeOrder(){
	//todo
}
//void run Report(Report report){
//todo
//}
void Shop::saveData(string aPath){
	ofstream dataFile;		//declare write stream
	dataFile.open(aPath);	//open write path
	unsigned int i, j;

	string data = "";						//construct data
	//data += to_string(orders.size());						//num of orders
	//data += "\n" + robotModels.size;			//num of robot models
	//data += "\n" + robotParts.size;				//num of robot parts
	data += "\n" + to_string(customers.size());				//num of customers
	data += "\n" + to_string(salesAssocs.size());			//num of sa

	/*
	for (i = 0; i < orders.size(); i++){		//fill orders data
		data += (orders[i]).toSave();			//order[i] data - ctor order
	}
	
	for (i = 0; i < robotModels.size; i++){	//fill rm data					TODO!!!
		data += (robotModels[i]).toSave();		//rm[i] data - ctor order + size of robot parts array
		for (j = 0; j < ((robotModels[i]).get_robotParts())->size; j++){//fill robot parts of model
			if (((robotModels[i]).get_robotParts())[j].partType == 1){
			}

		}
	}
	*/
	for (i = 0; i < customers.size(); i++){		//fill customer data
		data += (customers[i]).toSave();			//order[i] data - ctor order
	}
	for (i = 0; i < salesAssocs.size(); i++){		//fill orders data
		data += (salesAssocs[i]).toSave();			//order[i] data - ctor order
	}

	dataFile << data;	//write
	dataFile.close();	//close

}
void Shop::loadData(string aPath){
	ifstream dataFile;	//declare read stream
	dataFile.open(aPath);	//open the path
	int count;	//line counter
	int i;
	//int n_ord;
	//dataFile >> n_ord;	//store number of orders
	//models
	//parts
	int n_cust;
	dataFile >> n_cust;	//store number of customers
	int n_sa;
	dataFile >> n_sa;	//store number of salesassoc

	for (i = 0; i < n_cust; i++){	//add customers
		string n;
		dataFile >> n;
		int c;
		dataFile >> c;
		double w;
		dataFile >> w;
		AddCustomer(Customer(n, c, w));
	}
	for (i = 0; i < n_sa; i++){	//Sales Assoc
		string n;
		dataFile >> n;
		int e;
		dataFile >> e;
		AddSalesAssoc(SalesAssoc(n, e));
	}


}
