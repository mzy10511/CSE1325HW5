#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <vector>
//#include "RobotPart.h"
//#include "RobotModel.h"
//#include "Customer.h"
//#include "SalesAssoc.h"
//#include "Order.h"
//#include "Shop.h"
#include "AddPart.h" //------GS

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
//#include <FL/Fl_Widget.H>	//has Fl_Label
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Choice.H>	//Dropdown Menu
#include <FL/fl_ask.H>		//popup window
#include <Fl/Fl_Text_Display.H>		//Display pages of text (report)
//#include <FL/Fl_Group.H>
//#include <FL/Fl_Multiline_Output.H>

using namespace std;

//Global pointers for Forms
Fl_Input *input_cust_name;
Fl_Input *input_wallet;
Fl_Input *input_model_num;
Fl_Input *input_quantity;
Fl_Input *input_date;
Fl_Input *input_employee_name;
Fl_Input *input_employee_num;
Fl_Input *input_status;

Fl_Input *input_cust_num;

Fl_Window * window_c_model; //pointer for model ----GS

//Helper class/structs
//Helper class/struct for Create Order Form
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
		//Robotmodel model;
		CreateOrderForm(string n, double w, int m, int q, string d, string e_n, int e, string s): 
			name(n), wallet(w), model_num(m), quantity(q), date(d), employee_name(e_n), employee_num(e), status(s){};
};
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
class CreateSAForm{
public:
	string name;
	int number;
	CreateSAForm(string n, int num) :
		name(n), number(num){};
};

//Callbacks
//Create Order Callback
void cb_create_order(Fl_Widget* widget, void* data){	//callback handler for confirm order button
	//GJOB.AddOrder(((OrderForm*)data)->quantity, ((OrderForm*)data)->date, 
	//	Customer(((OrderForm*)data)->name, ((OrderForm*)data)->customer_num, ((OrderForm*)data)->wallet), 
	//	SalesAssoc(((OrderForm*)data)->employee_name, ((OrderForm*)data)->employee_num), 
	//	((OrderForm*)data)->!!!!!!!!!!ROBOTMODEL!!!!!!!!!!!!, ((OrderForm*)data)->status));

	fl_choice("Order Placed", "Ok", NULL, NULL);	//notifies user that order has been placed
}
//Create Cust Callback
void cb_create_cust(Fl_Widget* widget, void* data){	//callback handler for confirm info button (customer)
	//todo

	fl_choice("Customer Information Entered", "Ok", NULL, NULL);	//notifies user that info has been placed
}
//Create SA Callback
void cb_create_sa(Fl_Widget* widget, void* data){	//callback handler for confirm info button (sa)
	//todo

	fl_choice("Employee Information Entered", "Ok", NULL, NULL);	//notifies user that info has been placed
}
//Create Model Callback ------GS
void cancel_modelCB(Fl_Widget*w, void*p){
	window_c_model->hide();
}
//cb - create -robot component

//Save Callback -- not needed

//Forms
//Create Order Form
void CreateOrder(Fl_Widget*, void*){	
	Fl_Window *window_c_order = new Fl_Window(0, 90, 480, 370, "Create Order");
	window_c_order->begin();
	//start Window Widgets
	input_cust_name = new Fl_Input(140, 10, 330, 30, "Customer Name:");
	input_wallet = new Fl_Input(140, 50, 330, 30, "Wallet:");
	input_model_num = new Fl_Input(140, 90, 330, 30, "Model Number:");//Dropdown?
	/*Dropdown version of input model number
	Fl_Choice *choice_model_num = new Fl_Choice(140, 90, 330, 30, "Model Number");
	unsigned int i = 0;
	for (; i < GJOB.GetRobotModels()->size(); i++){
			choice_model_num->add(*GJOB.GetRobotModels())[i].get_modelNum();	//implement base code
	}
	*/
	input_quantity = new Fl_Input(140, 130, 330, 30, "Quantity:");
	input_date = new Fl_Input(140, 170, 330, 30, "Date:");
	input_employee_name = new Fl_Input(140, 210, 330, 30, "Employee Name:");
	input_employee_num = new Fl_Input(140, 250, 330, 30, "Employee Number:");
	input_status = new Fl_Input(140, 290, 330, 30, "Status:");

	Fl_Button *button_confirm = new Fl_Button(140, 330, 150, 30, "Confirm Order");
	//end Window Widgets

	//when confirm button is clicked, processes form
	button_confirm->callback(cb_create_order, new CreateOrderForm((string)(input_cust_name->value()), strtod(input_wallet->value(),NULL), 
		(int)(input_model_num->value()), (int)(input_quantity->value()), (string)(input_date->value()), (string)(input_employee_name->value()),
		(int)(input_employee_num->value()), (string)(input_status->value())));

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
	button_confirm->callback(cb_create_cust, new CreateCustForm((string)(input_cust_name->value()), strtod(input_wallet->value(), NULL),
		(int)(input_cust_num->value())));

	window_c_customer->end();

	window_c_customer->show();
}

//Create Sales Associate
void CreateSalesAssoc(Fl_Widget*, void*){								
	Fl_Window *window_c_sa = new Fl_Window(0, 90, 510, 130, "Create Sales Associate");
	window_c_sa->begin();
	//start Window Widgets
	input_employee_name = new Fl_Input(170, 10, 330, 30, "Sales Associate Name:");
	input_employee_num = new Fl_Input(170, 50, 330, 30, "Sales Associate Number:");

	Fl_Button *button_confirm = new Fl_Button(170, 90, 150, 30, "Confirm Profile");
	//end Window Widgets

	//when confirm button is clicked, processes form
	button_confirm->callback(cb_create_sa, new CreateSAForm((string)(input_employee_name->value()), (int)(input_employee_num->value())));

	window_c_sa->end();

	window_c_sa->show();
}
void CreateRobotModel(Fl_Widget*, void*p){								//Create Robot Model ----GS
	window_c_model = new Fl_Window(0, 90, 480, 330, "Creating Robot Model");
	window_c_model->begin();

	//widgets 
	Fl_Input * input_m_name = new Fl_Input(140, 30, 330, 30, "Robot Model Name:");
	Fl_Input * input_m_number = new Fl_Input(140, 90, 330, 30, "Robot Model Number:");
	Fl_Input * input_m_price = new Fl_Input(140, 150, 330, 30, "Robot Model Price:");

	Fl_Button * button_add_part = new Fl_Button(40, 210, 150, 30, "Add Part");
	button_add_part->callback(add_partCB);
	Fl_Button * button_create = new Fl_Button(260, 210, 150, 30, "Create");

	Fl_Button * button_cancel = new Fl_Button(260, 270, 150, 30, "Cancel");
	button_cancel->callback(cancel_modelCB);

	window_c_model->end();
	window_c_model->show();
}
void CreateRobotComponent(Fl_Widget*, void*){							//Create Robot Component
	//todo
}

void SaveGUI(Fl_Widget* w, void*){									//Save
	//todo
	fl_choice("Data Saved", "Ok", NULL, NULL);
}

void ReportOrder(Fl_Widget*, void*){									//Report Order
	Fl_Window *window_r_order = new Fl_Window(0, 90, 480, 480, "Report Order");
	window_r_order->begin();
	//start Window Widgets
	Fl_Text_Display *report = new Fl_Text_Display(0, 0, 480, 480);
	//use base code to compile report and display
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
	//end Window Widgets

	window_r_rp->end();

	window_r_rp->show();
}

void ExitGUI(Fl_Widget*, void*){									//Exit Program
	exit(0);
}

int GUI_start(){
	//Main GUI Window
	Fl_Window *window_main = new Fl_Window(0, 0, Fl::w(), Fl::h(), "Gaganjobs Robot Shop");

	//Main Menu Bar
	Fl_Menu_Bar *menu = new Fl_Menu_Bar(0, 0, Fl::w(), 30);				//Menu Bar

	menu->add("Create/Order", FL_CTRL + 'o', CreateOrder);					//Create > Order
	menu->add("Create/Customer", FL_CTRL + 'c', CreateCustomer);			//Create > Customer
	menu->add("Create/Sales Associate", FL_CTRL + 'a', CreateSalesAssoc);	//Create > Sales Associate
	menu->add("Create/Robot Model", FL_CTRL + 'm', CreateRobotModel);		//Create > Robot Model
	menu->add("Create/Robot Component", FL_CTRL + 'p', CreateRobotComponent);//Create > Robot Component

	menu->add("Save", FL_CTRL + 's', SaveGUI);							//Save

	menu->add("Report/Order", FL_CTRL + 'r', ReportOrder);					//Report > Order
	menu->add("Report/Customer", FL_CTRL + 'u', ReportCustomer);			//Report > Customer
	menu->add("Report/Sales Associate", FL_CTRL + 'l', ReportSalesAssoc);	//Report > Sales Associate
	menu->add("Report/Robot Model", FL_CTRL + 'd', ReportRobotModel);		//Report > Robot Model
	menu->add("Report/Robot Part", FL_CTRL + 't', ReportRobotPart);			//Report > Robot Part

	menu->add("Quit", FL_CTRL + 'q', ExitGUI);							//Quit

	//Show Window
	window_main->end();
	window_main->show();
	return Fl::run();
}

int main(){
	
	GUI_start();	//GUI

	return 0;
}

