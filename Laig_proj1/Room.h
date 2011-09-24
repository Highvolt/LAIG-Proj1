#ifndef _ROOM_H_
#define _ROOM_H_
#ifdef __APPLE__
#include <GLUI/GLUI.h>
#else
#include <gl\glui.h>
#endif
#include <math.h>

void draw_room(double x,double y,double z);
void draw_backwall(double x, double y, double z);
void draw_curve_wall(double x, double y, double z, int n_steps);
void draw_big_wall(double x, double y, double z);
#endif