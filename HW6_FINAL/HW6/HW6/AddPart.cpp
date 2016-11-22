/*#include "AddPart.h"
#include "RobotPart.h"

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
	input_p_description = new Fl_Multiline_Input(140, 230, 330, 90, "Part Description:");

	button_create = new Fl_Button(40, 300, 150, 30, "Create");
	button_cancel = new Fl_Button(260, 300, 150, 30, "Cancel");
	button_cancel->callback(cancel_robot_partCB);

	window_add_part->end();
	window_add_part->show();
}

void create_robot_partCB(Fl_Widget * w, void * p){ }

void add_partCB(Fl_Widget * w, void * p){
	add_part(w, p);

	my_arm->set_arm_name(input_p_name->value());
	
}

void cancel_robot_partCB(Fl_Widget * w, void * p){
	window_add_part->hide();
}*/