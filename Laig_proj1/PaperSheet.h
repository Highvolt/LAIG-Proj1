#ifndef _PAPERSHEET_H_
#define _PAPERSHEET_H_
#ifdef __APPLE__
#include <GLUI/GLUI.h>
#else
#include <glui.h>
#endif
#include <math.h>

void myBox(double dx, double dy, double dz);
void draw_machine(double x, double y, double z);
void draw_carpet(double x, double y, double z);
void draw_printer(double x, double y, double z);
void draw_teapot(double x, double y, double z);
void draw_printer_cylinder(double x, double y, double z);
void draw_guillotine(double x, double y, double z);

#endif
