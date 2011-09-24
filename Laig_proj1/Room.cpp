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

void draw_backwall(double x, double y, double z){
	

	glBegin(GL_POLYGON);
		glNormal3d(0.0,0.0,1.0);  // esta normal fica comum aos 4 vertices
		  glVertex3d(x, y, z);	
		  glVertex3d(x,y+room_height , z);	
		 glVertex3d(x+small_wall_part1, y+room_height,  z);	
		 glVertex3d(x+small_wall_part1, y,  z);
	glEnd();

	glBegin(GL_POLYGON);
		glNormal3d(0.0,0.0,1.0);  // esta normal fica comum aos 4 vertices
		glVertex3d(x+small_wall_part1, y+door_height, z);	
		  glVertex3d(x+small_wall_part1,y+room_height , z);	
		  glVertex3d(x+small_wall_part1+door_width, y+room_height,  z);	
		  glVertex3d(x+small_wall_part1+door_width, y+door_height,  z);
	glEnd();

		glBegin(GL_POLYGON);
		glNormal3d(0.0,0.0,1.0);  // esta normal fica comum aos 4 vertices
		glVertex3d(x+small_wall_part1+door_width, y, z);	
		  glVertex3d(x+small_wall_part1+door_width,y+room_height , z);	
		  glVertex3d(x+small_wall, y+room_height,  z);	
		  glVertex3d(x+small_wall, y,  z);
	glEnd();

}

void draw_curve_wall(double x, double y, double z, int n_steps){
	double z_step=big_wall_width/n_steps;
	double wave_lenght=PI/big_wall_width;
	double z_ant=z;
	double x_ant=x;
	for(int i=0; i<=n_steps;i++){
		double new_x=x+sin(i*z_step*wave_lenght)*10;
		double new_z=z+z_step*i;
		//printf("anteriores: x:%f z:%f novas: x:%f z:%f\n",x_ant,z_ant,new_x,new_z);
		glBegin(GL_POLYGON);
			glNormal3d(-1.0,0.0,0.0);  // esta normal fica comum aos 4 vertices
			glVertex3d(x_ant, y, z_ant);	
			glVertex3d(x_ant,y+room_height , z_ant);	
			glVertex3d(new_x, y+room_height,  new_z);	
			glVertex3d(new_x, y,  new_z);
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