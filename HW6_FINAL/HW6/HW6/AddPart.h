#ifndef __ADDPART_H
#define __ADDPART_H
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Choice.H>
#include <iostream>
#include <string.h>

using namespace std;

void add_partCB(Fl_Widget* w, void * p);
void create_robot_partCB(Fl_Widget * w, void * p);
void cancel_robot_partCB(Fl_Widget * w, void * p);
void add_part(Fl_Widget*, void*);

#endif