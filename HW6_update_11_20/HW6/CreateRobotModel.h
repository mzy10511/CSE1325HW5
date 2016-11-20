#ifndef __CREATEROBOTMODEL_H
#define __CREATEROBOTMODEL_H

#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Choice.H>
#include <iostream>
#include <string.h>
#include "AddPart.h"

using namespace std;

void CreateRobotModel(Fl_Widget *w, void *p);
void cancel_modelCB(Fl_Widget * w, void * p);
#endif