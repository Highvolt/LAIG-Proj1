#ifndef _ROOM_H_
#define _ROOM_H_
#ifdef __APPLE__
#include <GLUI/GLUI.h>
#else
#include <glui.h>
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
    void normalize(){
        double modulo=sqrt(pow(x,2.0)+pow(y, 2.0)+pow(z, 2.0));
        x=x/modulo;
        y=y/modulo;
        z=z/modulo;
    }
    vector3d operator-(const vector3d & b) const{
        return vector3d(this->x-b.x,this->y-b.y,this->z-b.z);
    }
   /* vector3d & operator=(const vector3d &b){
        return *this;
    }*/
    
};

double get_x_room_mov();
double get_z_room_mov();
void draw_room(double x,double y,double z);
void draw_backwall(double x, double y, double z);
void draw_curve_wall(double x, double y, double z, int n_steps, int n_vsteps);
void draw_big_wall(double x, double y, double z);
void draw_ceiling(double x, double y, double z);
void draw_floor(double x, double y, double z);
void draw_impostors(double x,double y, double z);
double get_door_distance();
double get_doorwidth();
double get_room_height();
void draw_frontwall(double x, double y, double z);
#endif
