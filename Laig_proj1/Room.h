#ifndef _ROOM_H_
#define _ROOM_H_
#ifdef __APPLE__
#include <GLUI/GLUI.h>
#else
#include <gl\glui.h>
#endif
#include <math.h>

class vector3d {
public:
    double x,y,z;
    vector3d(double x,double y,double z){
        this->x=x;
        this->y=y;
        this->z=z;
    }
    vector3d(){}
    vector3d operator-(const vector3d & b) const{
        return vector3d(this->x-b.x,this->y-b.y,this->z-b.z);
    }
   /* vector3d & operator=(const vector3d &b){
        return *this;
    }*/
    
};

void draw_room(double x,double y,double z);
void draw_backwall(double x, double y, double z);
void draw_curve_wall(double x, double y, double z, int n_steps);
void draw_big_wall(double x, double y, double z);
#endif