#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <vector>
#include <sstream>
#include "RobotPart.h"
#include "RobotModel.h"			
#include "Customer.h"			//MY 11/21-1
#include "SalesAssoc.h"			//MY 11/21-1
#include "Order.h"
#include "Shop.h"
#include "AddPart.h"
#include <string>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Widget.H>	//has Fl_Label
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Choice.H>	//Dropdown Menu
#include <FL/fl_ask.H>		//popup window
#include <Fl/Fl_Text_Display.H>		//Display pages of text (report)
#include <FL/Fl_Group.H>
#include <FL/Fl_Multiline_Output.H>

using namespace std;
//global
Shop * GJOB;
//--------------------------------------------------------------------------------
//adding part
//methods
void add_partCB(Fl_Widget* w, void * p);
void create_robot_partCB(Fl_Widget * w, void * p);
void cancel_robot_partCB(Fl_Widget * w, void * p);
void add_part(Fl_Widget*, void*);

//window and widgets
Fl_Window * window_add_part;
Fl_Input * input_p_name;
Fl_Choice * choice_p_type;
Fl_Input * input_p_number;
Fl_Input * input_p_price;
Fl_Input * input_p_weight;
Fl_Multiline_Input * input_p_description;
Fl_Button * button_create;
Fl_Button * button_cancel;
Arm * my_arm;           
Head * my_head;
Battery * my_battery;
Torso * my_torso;
Motor * my_motor;

void add_part(Fl_Widget *, void*){
	window_add_part = new Fl_Window(30, 120, 480, 370, "Add Part");
	window_add_part->begin();

	//widgets
	input_p_name = new Fl_Input(140, 30, 330, 30, "Part Name:");
	choice_p_type = new Fl_Choice(140, 70, 330, 30, "Part Type:");
	choice_p_type->add("Head");
	choice_p_type->add("Torso");
	choice_p_type->add("Arm");
	choice_p_type->add("Battery");
	choice_p_type->add("Motor");
	input_p_number = new Fl_Input(140, 110, 330, 30, "Part Number:");
	input_p_price = new Fl_Input(140, 150, 330, 30, "Part Price:");
	input_p_weight = new Fl_Input(140, 190, 330, 30, "Part Weight:");
	input_p_description = new Fl_Multiline_Input(140, 230, 330, 70, "Part Description:");

	button_create = new Fl_Button(40, 300, 150, 30, "Create");
	button_create->callback(create_robot_partCB);
	button_cancel = new Fl_Button(260, 300, 150, 30, "Cancel");
	button_cancel->callback(cancel_robot_partCB);

	window_add_part->end();
	window_add_part->show();
}

void create_robot_partCB(Fl_Widget * w, void * p){ 
	if (choice_p_type->value() == 2){
		my_arm = new Arm;
		my_arm->set_arm_name(input_p_name->value());
		my_arm->set_arm_description(input_p_description->value());
		my_arm->set_arm_partNum(atof(input_p_number->value()));
		my_arm->set_arm_price(atof(input_p_price->value()));
		GJOB->AddRobotPart(my_arm);
	}

	if (choice_p_type->value() == 0){
		my_head = new Head;
		my_head->set_head_name(input_p_name->value());
		my_head->set_head_description(input_p_description->value());
		my_head->set_head_partNum(atof(input_p_number->value()));
		my_head->set_head_price(atof(input_p_price->value()));
		GJOB->AddRobotPart(my_head);
	}

	if (choice_p_type->value() == 1){
		my_torso = new Torso;
		my_torso->set_torso_name(input_p_name->value());
		my_torso->set_torso_description(input_p_description->value());
		my_torso->set_torso_partNum(atof(input_p_number->value()));
		my_torso->set_torso_price(atof(input_p_price->value()));
		GJOB->AddRobotPart(my_torso);
	}

	if (choice_p_type->value() == 3){
		my_battery = new Battery;
		my_battery->set_battery_name(input_p_name->value());
		my_battery->set_battery_description(input_p_description->value());
		my_battery->set_battery_partNum(atof(input_p_number->value()));
		my_battery->set_battery_price(atof(input_p_price->value()));
		GJOB->AddRobotPart(my_battery);
	}

	if (choice_p_type->value() == 4){
		my_motor = new Motor;
		my_motor->set_motor_name(input_p_name->value());
		my_motor->set_motor_description(input_p_description->value());
		my_motor->set_motor_partNum(atof(input_p_number->value()));
		my_motor->set_motor_price(atof(input_p_price->value()));
		GJOB->AddRobotPart(my_motor);
	}

	window_add_part->hide();
	free(window_add_part);
}

void add_partCB(Fl_Widget * w, void * p){
	add_part(w, p);
}

void cancel_robot_partCB(Fl_Widget * w, void * p){ 
	window_add_part->hide();
}
//--------------------------------------------------------------------------

//-------------------------------------------------------------------------
//Global pointers for Forms
Fl_Input *input_cust_name;
Fl_Input *input_wallet;
Fl_Input *input_model_num;
Fl_Input *input_quantity;
Fl_Input *input_date;
Fl_Input *input_employee_name;
Fl_Input *input_employee_num;
Fl_Input *input_status;
Fl_Choice * choice_model_num;

Fl_Input *input_cust_num;

//Helper class/structs

//Global pointer for order
Fl_Window * window_c_order;//------------------GSGSGSGGSGGGSGSGSGSGSSGG

//Helper class/struct for Create Order Form
/*
class CreateOrderForm{
public:
	string name;
	double wallet;
	int model_num;
	int quantity;
	string date;
	string employee_name;
	int employee_num;
	string status;
	Robotmodel model;
	CreateOrderForm(string n, double w, int m, int q, string d, string e_n, int e, string s) :
		name(n), wallet(w), model_num(m), quantity(q), date(d), employee_name(e_n), employee_num(e), status(s){
		unsigned int i;
		for (i = 0; i < GJOB->GetRobotModels()->size(); i++){
			if ((*GJOB->GetRobotModels())[i].get_modelNum() == model_num){
				model = (*GJOB->GetRobotModels())[i];
				break;
			}
			else{
				fl_choice("Invalid Robot Model", "Ok", NULL, NULL);
			}
		}
	};
};
*/
//Helper class/struct for Create Customer Form
class CreateCustForm{
public:
	string name;
	double wallet;
	int number;
	CreateCustForm(string n, double w, int num) :
		name(n), wallet(w), number(num){};
};

//Helper class/struct for Create Sales Associate Form
//Global pointer for SA
Fl_Window *window_c_sa;//----------------------GSGGGSGSGSGSGSGGSGSGSGSGS
class CreateSAForm{
public:
	string name;
	int number;
	CreateSAForm(string n, int num) :
		name(n), number(num){};
};
//-------------------------------------------------------------------------------------------

//Callbacks
//Create Order Callback

void cb_create_order(Fl_Widget* w, void* p){
	Order oo;
	Customer cc;
	cc.SetName(input_cust_name->value());
	cc.SetWallet(atof(input_wallet->value()));
	cc.SetNum(atof(input_cust_num->value()));
	oo.SetCustomer(cc);
	SalesAssoc sasa;
	sasa.SetName(input_employee_name->value());
	sasa.SetNum(atof(input_employee_num->value()));
	oo.SetSalesAssoc(sasa);
	oo.SetStatus(input_status->value());
	GJOB->AddOrder(oo);

	fl_choice("Order Placed", "Ok", NULL, NULL);	//notifies user that order has been placed
	window_c_order->hide();
	free(window_c_order);
}

//Create Cust Callback
void cb_create_cust(Fl_Widget* widget, void* data){	//callback handler for confirm info button (customer)
	Customer cust;
	cust.SetName(input_cust_name->value());
	cust.SetWallet(atof(input_wallet->value()));
	cust.SetNum(atof(input_cust_num->value()));
	GJOB->AddCustomer(cust);

	fl_choice("Customer Information Entered", "Ok", NULL, NULL);	//notifies user that info has been placed

}

//Create SA Callback
void cb_create_sa(Fl_Widget* widget, void* data){	//callback handler for confirm info button (sa)
	SalesAssoc sa;
	sa.SetName(input_employee_name->value());
	sa.SetNum(atof(input_employee_num->value()));
	GJOB->AddSalesAssoc(sa);

	fl_choice("Employee Information Entered", "Ok", NULL, NULL);	//notifies user that info has been placed
	window_c_sa->hide();
	free(window_c_sa);
}

//Create Model Callback

//globals for model CB
Fl_Window * window_c_model; //pointer for cancel model

Fl_Input * input_m_name;
Fl_Input * input_m_price;
Fl_Input * input_m_number;
Fl_Button * button_add_part;
Fl_Button * m_create;
Fl_Button * m_cancel;

Robotmodel aModel;

void cancel_modelCB(Fl_Widget*w, void*p){
	window_c_model->hide();
}

void create_model_robot_partCB(Fl_Widget* w, void* p){
	if (choice_p_type->value() == 2){
		my_arm = new Arm;
		my_arm->set_arm_name(input_p_name->value());
		my_arm->set_arm_description(input_p_description->value());
		my_arm->set_arm_partNum(atof(input_p_number->value()));
		my_arm->set_arm_price(atof(input_p_price->value()));
		aModel.add_part(*my_arm);
	}

	if (choice_p_type->value() == 0){
		my_head = new Head;
		my_head->set_head_name(input_p_name->value());
		my_head->set_head_description(input_p_description->value());
		my_head->set_head_partNum(atof(input_p_number->value()));
		my_head->set_head_price(atof(input_p_price->value()));
		aModel.add_part(*my_head);
	}

	if (choice_p_type->value() == 1){
		my_torso = new Torso;
		my_torso->set_torso_name(input_p_name->value());
		my_torso->set_torso_description(input_p_description->value());
		my_torso->set_torso_partNum(atof(input_p_number->value()));
		my_torso->set_torso_price(atof(input_p_price->value()));
		aModel.add_part(*my_torso);
	}

	if (choice_p_type->value() == 3){
		my_battery = new Battery;
		my_battery->set_battery_name(input_p_name->value());
		my_battery->set_battery_description(input_p_description->value());
		my_battery->set_battery_partNum(atof(input_p_number->value()));
		my_battery->set_battery_price(atof(input_p_price->value()));
		aModel.add_part(*my_battery);
	}

	if (choice_p_type->value() == 4){
		my_motor = new Motor;
		my_motor->set_motor_name(input_p_name->value());
		my_motor->set_motor_description(input_p_description->value());
		my_motor->set_motor_partNum(atof(input_p_number->value()));
		my_motor->set_motor_price(atof(input_p_price->value()));
		aModel.add_part(*my_motor);
	}

	window_add_part->hide();
	free(window_add_part);
}

void add_part_modelCB(Fl_Widget* w, void* p){
	window_add_part = new Fl_Window(30, 120, 480, 370, "Add Part");
	window_add_part->begin();

	//widgets
	input_p_name = new Fl_Input(140, 30, 330, 30, "Part Name:");
	choice_p_type = new Fl_Choice(140, 70, 330, 30, "Part Type:");
	choice_p_type->add("Head");
	choice_p_type->add("Torso");
	choice_p_type->add("Arm");
	choice_p_type->add("Battery");
	choice_p_type->add("Motor");
	input_p_number = new Fl_Input(140, 110, 330, 30, "Part Number:");
	input_p_price = new Fl_Input(140, 150, 330, 30, "Part Price:");
	input_p_weight = new Fl_Input(140, 190, 330, 30, "Part Weight:");
	input_p_description = new Fl_Multiline_Input(140, 230, 330, 70, "Part Description:");

	button_create = new Fl_Button(40, 300, 150, 30, "Create");
	button_create->callback(create_model_robot_partCB);
	button_cancel = new Fl_Button(260, 300, 150, 30, "Cancel");
	button_cancel->callback(cancel_robot_partCB);

	window_add_part->end();
	window_add_part->show();
}

void create_modelCB(Fl_Widget* w, void* p){
	aModel.set_name(input_m_name->value());
	aModel.set_price(atof(input_m_name->value()));
	aModel.set_modelNum(atof(input_m_number->value()));
	GJOB->AddRobotModel(aModel);
	window_c_model->hide();
	free(window_c_model);
}

//globals for Sales Assoc Orders				-GS4am
Fl_Window * window_sao;
Fl_Input* input_sao_id;

void find_sales_orderCB(Fl_Widget* w, void* p){
	unsigned int i = 0;
	string s = "";
	int checkid = atof(input_sao_id->value());
	for (; i < (GJOB->GetOrders())->size(); i++){
		SalesAssoc checkassoc = ((GJOB->GetOrders())->at(i)).GetSalesAssoc();
		if (checkassoc.GetNum() == checkid){
			s += ((GJOB->GetOrders())->at(i)).toString() + "\n\n";
		}
	}

	Fl_Window* window_fsao = new Fl_Window(50, 150, 500, 400, "Orders by Sales Associate");
	window_fsao->begin();
	Fl_Text_Display * report = new Fl_Text_Display(10, 10, 380, 380);
	Fl_Text_Buffer* buff = new Fl_Text_Buffer;
	report->buffer(buff);
	buff->text(s.c_str());

	window_fsao->end();
	window_fsao->show();
}
//Save Callback -- not needed

//--------------------------------------------------------------------------------------


//Forms
//Create Order Form

void CreateOrder(Fl_Widget*, void*){	
	window_c_order = new Fl_Window(0, 90, 490, 420, "Create Order");
	window_c_order->begin();
	//start Window Widgets
	input_cust_name = new Fl_Input(140, 10, 330, 30, "Customer Name:");
	input_wallet = new Fl_Input(140, 50, 330, 30, "Wallet:");
	input_cust_num = new Fl_Input(140, 90, 330, 30, "Customer Number:");
	choice_model_num = new Fl_Choice(140, 130, 330, 30, "Model Number");
	unsigned int i = 0;
	vector<Robotmodel>* rmv = GJOB->GetRobotModels();
	for (; i < rmv->size(); i++){
		string cadd = rmv->at(i).get_name();
		choice_model_num->add(cadd.c_str());	//implement base code
	}
	
	input_quantity = new Fl_Input(140, 170, 330, 30, "Quantity:");
	input_date = new Fl_Input(140, 210, 330, 30, "Date:");
	input_employee_name = new Fl_Input(140, 250, 330, 30, "Employee Name:");
	input_employee_num = new Fl_Input(140, 290, 330, 30, "Employee Number:");
	input_status = new Fl_Input(140, 330, 330, 30, "Status:");

	Fl_Button *button_confirm = new Fl_Button(140, 370, 150, 30, "Confirm Order");
	//end Window Widgets

	//when confirm button is clicked, processes form
	button_confirm->callback(cb_create_order);

	window_c_order->end();

	window_c_order->show();
}

//Create Customer Form
void CreateCustomer(Fl_Widget*, void*){
	Fl_Window *window_c_customer = new Fl_Window(0, 90, 480, 170, "Create Customer");
	window_c_customer->begin();
	//start Window Widgets
	input_cust_name = new Fl_Input(140, 10, 330, 30, "Customer Name:");
	input_wallet = new Fl_Input(140, 50, 330, 30, "Wallet:");
	input_cust_num = new Fl_Input(140, 90, 330, 30, "Customer Number:");

	Fl_Button *button_confirm = new Fl_Button(140, 130, 150, 30, "Confirm Profile");
	//end Window Widgets

	//when confirm button is clicked, processes form
	button_confirm->callback(cb_create_cust);

	window_c_customer->end();

	window_c_customer->show();
}

//Create Sales Associate
void CreateSalesAssoc(Fl_Widget*, void*){								
	window_c_sa = new Fl_Window(0, 90, 510, 130, "Create Sales Associate");
	window_c_sa->begin();
	//start Window Widgets
	input_employee_name = new Fl_Input(170, 10, 330, 30, "Sales Associate Name:");
	input_employee_num = new Fl_Input(170, 50, 330, 30, "Sales Associate Number:");

	Fl_Button *button_confirm = new Fl_Button(170, 90, 150, 30, "Confirm Profile");
	//end Window Widgets

	//when confirm button is clicked, processes form
	button_confirm->callback(cb_create_sa);

	window_c_sa->end();

	window_c_sa->show();
}
void CreateRobotModel(Fl_Widget*, void*p){								//Create Robot Model
	window_c_model = new Fl_Window(0, 90, 480, 330, "Creating Robot Model");
	window_c_model->begin();

	//widgets 
	input_m_name = new Fl_Input(140, 30, 330, 30, "Robot Model Name:");
	input_m_number = new Fl_Input(140, 90, 330, 30, "Robot Model Number:");
	input_m_price = new Fl_Input(140, 150, 330, 30, "Robot Model Price:");

	button_add_part = new Fl_Button(40, 210, 150, 30, "Add Part");
	button_add_part->callback(add_partCB);
	m_create = new Fl_Button(260, 210, 150, 30, "Create");
	m_create->callback(create_modelCB);
	m_cancel = new Fl_Button(260, 270, 150, 30, "Cancel");
	m_cancel->callback(cancel_modelCB);

	window_c_model->end();
	window_c_model->show();
}
void CreateRobotComponent(Fl_Widget* w, void* p){							//Create Robot Component
	add_part(w, p);
}

void SaveGUI(Fl_Widget* w, void*){									//Save
	string dataPath;
	dataPath = fl_input("Data Path", "a");
	if (strcmp((dataPath.c_str()),"a")){
		GJOB->saveData(dataPath);
		fl_choice("Data Saved", "Ok", NULL, NULL);
		
	}
	else{
		fl_choice("Data Save Canceled", "Ok", NULL, NULL);
	}
	
}

void LoadGUI(Fl_Widget* w, void*){									//Load
	string dataPath;
	dataPath = fl_input("Data Path", "a");
	if (strcmp((dataPath.c_str()), "a")){
		GJOB->loadData(dataPath);
		fl_choice("Data Loaded", "Ok", NULL, NULL);
	}
	else{
		fl_choice("Data Load Canceled", "Ok", NULL, NULL);
	}
}

void ReportOrder(Fl_Widget*, void*){									//Report Order
	Fl_Window *window_r_order = new Fl_Window(0, 90, 480, 480, "Report Order");
	window_r_order->begin();
	//start Window Widgets

	Fl_Text_Display *report = new Fl_Text_Display(10, 10, 460, 460);
	//use base code to compile report and display
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();		//create text buffer
	report->buffer(buff);

	unsigned int i = 0;
	double total = 0;
	string data = "";
	for (; i < (GJOB->GetOrders())->size(); i++){
		data += (GJOB->GetOrders())->at(i).toString() + "\n";	//get order data
	}

	buff->text(data.c_str());
	//end Window Widgets

	window_r_order->end();

	window_r_order->show();
}

void ReportCustomer(Fl_Widget*, void*){									//Report Customer
	Fl_Window *window_r_customer = new Fl_Window(0, 90, 480, 480, "Report Customer");
	window_r_customer->begin();
	//start Window Widgets
	Fl_Text_Display *report = new Fl_Text_Display(0, 0, 480, 480);

	//use base code to compile report and display
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();		//create text buffer
	report->buffer(buff);

	unsigned int i = 0, j = 0;
	double total = 0;
	string data = "";
	for (; i < (GJOB->GetCustomers())->size(); i++){
		data += (GJOB->GetCustomers())->at(i).GetName() + "\n";	//get name
		for (total = 0; j < (GJOB->GetOrders())->size(); j++){		//set total = 0, calc + get price
			if (((GJOB->GetOrders()->at(j).GetCustomer().GetName()) == (GJOB->GetCustomers())->at(i).GetName())){
				total += GJOB->GetOrders()->at(j).totalPrice();
			}
		}
		data += total;
		data += "\n";
	}

	buff->text(data.c_str());
	//end Window Widgets

	window_r_customer->end();

	window_r_customer->show();
}

void ReportSalesAssoc(Fl_Widget*, void*){								//Report Sales Associate
	Fl_Window *window_r_sa = new Fl_Window(0, 90, 480, 480, "Report Sales Associate");
	window_r_sa->begin();
	//start Window Widgets
	Fl_Text_Display *report = new Fl_Text_Display(0, 0, 480, 480);

	//use base code to compile report and display
	Fl_Text_Buffer *buff = new Fl_Text_Buffer();		//create text buffer
	report->buffer(buff);

	unsigned int i = 0, j = 0;
	double total = 0;
	string data = "";
	for (; i < (GJOB->GetSalesAssoc())->size(); i++){
		data += (GJOB->GetSalesAssoc())->at(i).GetName() + "\n";	//get name
		for (total = 0; j < (GJOB->GetOrders())->size(); j++){		//set total = 0, calc + get price
			if (((GJOB->GetOrders()->at(j).GetSalesAssoc().GetName()) == (GJOB->GetSalesAssoc())->at(i).GetName())){
				total += GJOB->GetOrders()->at(j).totalPrice();
				data += (GJOB->GetOrders())->at(i).toString() + "\n";	//get order data
			}
		}
		data += total;
		data += "\n";
	}
	buff->text(data.c_str());
	//end Window Widgets

	window_r_sa->end();

	window_r_sa->show();
}

void ReportRobotModel(Fl_Widget*, void*){								//Report Robot Model
	Fl_Window *window_r_rm = new Fl_Window(0, 90, 480, 480, "Report Robot Model");
	window_r_rm->begin();
	//start Window Widgets
	Fl_Text_Display *report = new Fl_Text_Display(0, 0, 480, 480);
	//use base code to compile report and display
	string s = GJOB->get_full_string_models(GJOB->GetRobotModels());
	Fl_Text_Buffer * buff = new Fl_Text_Buffer();
	report->buffer(buff);
	buff->text(s.c_str());

	//end Window Widgets

	window_r_rm->end();

	window_r_rm->show();
}
void ReportRobotPart(Fl_Widget*, void*){								//Report Robot Part
	Fl_Window *window_r_rp = new Fl_Window(0, 90, 480, 480, "Report Robot Part");
	window_r_rp->begin();
	//start Window Widgets
	Fl_Text_Display *report = new Fl_Text_Display(0, 0, 480, 480);
	//use base code to compile report and display
	vector<Robotpart*>* parts = GJOB->GetRobotParts();
	string s = GJOB->get_full_string_parts(parts);
	Fl_Text_Buffer * buff = new Fl_Text_Buffer();
	report->buffer(buff);
	buff->text(s.c_str());
	//end Window Widgets

	window_r_rp->end();

	window_r_rp->show();
}
void ReportSalesAssocOrder(Fl_Widget *w, void* p){			//gs4am
	window_sao = new Fl_Window(0, 90, 300, 100, "Orders by Sales Associate");
	window_sao->begin();

	input_sao_id = new Fl_Input(140, 10, 150, 30, "Enter Associate ID:");
	Fl_Button * findSA = new Fl_Button(80, 50, 100, 30, "Find Orders");
	findSA->callback(find_sales_orderCB);

	window_sao->end();
	window_sao->show();
}
void ExitGUI(Fl_Widget*, void*){									//Exit Program
	exit(0);
}

int GUI_start(){
	//Main GUI Window
	Fl_Window *window_main = new Fl_Window(0, 0, Fl::w()-400, Fl::h()-250, "Gaganjobs Robot Shop");

	//Main Menu Bar
	Fl_Menu_Bar *menu = new Fl_Menu_Bar(0, 0, Fl::w(), 30);				//Menu Bar

	menu->add("File/Save", FL_CTRL + 's', SaveGUI);							//File > Save
	menu->add("File/Load", FL_CTRL + 'l', LoadGUI);							//File > Load

	menu->add("Create/Order", FL_CTRL + 'o', CreateOrder);					//Create > Order
	menu->add("Create/Customer", FL_CTRL + 'c', CreateCustomer);			//Create > Customer
	menu->add("Create/Sales Associate", FL_CTRL + 'a', CreateSalesAssoc);	//Create > Sales Associate
	menu->add("Create/Robot Model", FL_CTRL + 'm', CreateRobotModel);		//Create > Robot Model
	menu->add("Create/Robot Component", FL_CTRL + 'p', CreateRobotComponent);//Create > Robot Component

	menu->add("Report/Order", FL_CTRL + 'r', ReportOrder);					//Report > Order
	menu->add("Report/Customer", FL_CTRL + 'u', ReportCustomer);			//Report > Customer
	menu->add("Report/Sales Associate", FL_CTRL + 'i', ReportSalesAssoc);	//Report > Sales Associate
	menu->add("Report/Orders by Sales Associates", FL_CTRL + 'g', ReportSalesAssocOrder);
	menu->add("Report/Robot Model", FL_CTRL + 'd', ReportRobotModel);		//Report > Robot Model
	menu->add("Report/Robot Part", FL_CTRL + 't', ReportRobotPart);			//Report > Robot Part

	menu->add("Quit", FL_CTRL + 'q', ExitGUI);							//Quit

	//Show Window
	window_main->end();
	window_main->show();
	return Fl::run();
}

int main(){
	GJOB = new Shop(); //Set up background code
	GUI_start();	//Run GUI

	return 0;
}

