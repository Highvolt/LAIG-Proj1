#ifndef _PAPERSHEET_H_
#define _PAPERSHEET_H_
#ifdef __APPLE__
#include <GLUI/GLUI.h>
#else
#include <gl/glui.h>
#endif
#include <math.h>

void draw_machine(double x, double y, double z);
void draw_carpet(double x, double y, double z);

#endif
