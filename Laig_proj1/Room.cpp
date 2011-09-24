#include "Room.h"
#include <stdio.h>

 #define PI 3.1415926535897932384626433

double room_height=25.0;
double ratio=1.74;
double small_wall=46.0;
double small_wall_part1=small_wall*0.6;
double door_height=room_height/2;
double door_width=small_wall*0.25;
double big_wall_width=small_wall*ratio;
double big_window_width=big_wall_width*0.6;
double big_window_height=room_height*0.70;
double big_window_bottom_wall_height=room_height*0.12;
double big_window_top_wall_height=room_height*0.18;
double big_wall_width_1=big_wall_width*0.25;
double big_wall_width_2=big_wall_width*0.15;

void draw_room(double x,double y,double z){
	draw_backwall(x,y,z);
	draw_curve_wall(x+small_wall,y,z,10);
    draw_big_wall(x, y, z);
}



/*
 Set Vector U to (Triangle.p2 minus Triangle.p1)
Set Vector V to (Triangle.p3 minus Triangle.p1)

Set Normal.x to (multiply U.y by V.z) minus (multiply U.z by V.y)
Set Normal.y to (multiply U.z by V.x) minus (multiply U.x by V.z)
Set Normal.z to (multiply U.x by V.y) minus (multiply U.y by V.x)

Returning Normal
*/

vector3d normalvec(vector3d & p1, vector3d & p2, vector3d & p3) {
    vector3d u= p2-p1;
    vector3d v= p3-p1;
    vector3d normal;
    normal.x=(u.y*v.z)-(u.z*v.y);
    normal.y=(u.z*v.x)-(u.x*v.z);
    normal.z=(u.x*v.y)-(u.y*v.x);
    normal.normalize();
    return normal;
}

void draw_backwall(double x, double y, double z){

//canto esquerdo
	glBegin(GL_POLYGON);
		glNormal3d(0.0,0.0,1.0);  // esta normal fica comum aos 4 vertices
		glVertex3d(x+small_wall_part1, y,  z); 
     glVertex3d(x+small_wall_part1, y+room_height,  z);	    
    glVertex3d(x,y+room_height , z);	
    glVertex3d(x, y, z);	
		  
		
		 
	glEnd();
//ombreira da porta
	glBegin(GL_POLYGON);
		glNormal3d(0.0,0.0,1.0);  // esta normal fica comum aos 4 vertices
	  glVertex3d(x+small_wall_part1+door_width, y+door_height,  z);	
     glVertex3d(x+small_wall_part1+door_width, y+room_height,  z);	
    glVertex3d(x+small_wall_part1,y+room_height , z);	
    glVertex3d(x+small_wall_part1, y+door_height, z);	
		  
		 
//canto direito
	glEnd();

		glBegin(GL_POLYGON);
		glNormal3d(0.0,0.0,1.0);  // esta normal fica comum aos 4 vertices
	glVertex3d(x+small_wall, y,  z);	
     glVertex3d(x+small_wall, y+room_height,  z);	
      glVertex3d(x+small_wall_part1+door_width,y+room_height , z);	
    glVertex3d(x+small_wall_part1+door_width, y, z);	
		
		 
		  
	glEnd();

}

void draw_curve_wall(double x, double y, double z, int n_steps){
	double z_step=big_wall_width/n_steps;
	double wave_lenght=PI/big_wall_width;
	double z_ant=z;
	double x_ant=x;
    vector3d normal;
	for(int i=0; i<=n_steps;i++){
		double new_x=x+sin(i*z_step*wave_lenght)*10;
		double new_z=z+z_step*i;
        vector3d p1(new_x, y,  new_z);
        p1.normalize();
        vector3d p2(new_x, y+room_height,  new_z);
        p2.normalize();
        vector3d p3(x_ant,y+room_height , z_ant);
        p3.normalize();
        normal=normalvec(p1,p2,p3);
		//printf("anteriores: x:%f z:%f novas: x:%f z:%f\n",x_ant,z_ant,new_x,new_z);
		glBegin(GL_POLYGON);
			glNormal3d(normal.x,normal.y,normal.z);  // esta normal fica comum aos 4 vertices
            glVertex3d(new_x, y,  new_z);
            glVertex3d(new_x, y+room_height,  new_z);
            glVertex3d(x_ant,y+room_height , z_ant);	
            glVertex3d(x_ant, y, z_ant);	
		glEnd();
		z_ant=new_z;
		x_ant=new_x;
    }


}


void draw_big_wall(double x, double y, double z){
   //primeira parte parede completa junto a parte do fundo
    glBegin(GL_POLYGON);
    glNormal3d(1.0,0.0,0.0);  // esta normal fica comum aos 4 vertices
    glVertex3d(x, y, z);	
    glVertex3d(x,y+room_height , z);	
    glVertex3d(x, y+room_height,  z+big_wall_width_2);	
    glVertex3d(x, y,  z+big_wall_width_2);
	glEnd();
  //parte de baixo da janela  
    glBegin(GL_POLYGON);
    glNormal3d(1.0,0.0,0.0);  // esta normal fica comum aos 4 vertices
    glVertex3d(x, y, z+big_wall_width_2);	
    glVertex3d(x,y+big_window_bottom_wall_height , z+big_wall_width_2);	
    glVertex3d(x, y+big_window_bottom_wall_height,  z+big_wall_width_2+big_window_width);	
    glVertex3d(x, y,  z+big_wall_width_2+big_window_width);
	glEnd();
  //parte de cima  
    glBegin(GL_POLYGON);
    glNormal3d(1.0,0.0,0.0);  // esta normal fica comum aos 4 vertices
    glVertex3d(x, y+big_window_height, z+big_wall_width_2);	
    glVertex3d(x,y+room_height , z+big_wall_width_2);	
    glVertex3d(x, y+room_height,  z+big_wall_width_2+big_window_width);	
    glVertex3d(x, y+big_window_height,  z+big_wall_width_2+big_window_width);
	glEnd();
    
 //parte depois da janela
    glBegin(GL_POLYGON);
    glNormal3d(1.0,0.0,0.0);  // esta normal fica comum aos 4 vertices
    glVertex3d(x, y, z+big_wall_width_2+big_window_width);	
    glVertex3d(x,y+room_height , z+big_wall_width_2+big_window_width);	
    glVertex3d(x, y+room_height,  z+big_wall_width);	
    glVertex3d(x, y,  z+big_wall_width);
	glEnd();
    
    
}