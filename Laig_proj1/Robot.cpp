#include "Robot.h"

double robot_width=4;
double robot_length=4;
double robot_height=4;
double rims_size=4;

void draw_robot(double x, double y, double z){
    draw_box(x,y , z);
    
    
}

void draw_wheels(){

}

void draw_box(double x, double y, double z){
 
    //Parede 1 begin
    glBegin(GL_POLYGON);
    glNormal3d(0.0,0.0,1.0);  // esta normal fica comum aos 4 vertices
    glVertex3d(x-robot_width/2, y+robot_height,  z-robot_length/2); 
    glVertex3d(x-robot_width/2, y,  z-robot_length/2);   
    glVertex3d(x+robot_width/2, y,  z-robot_length/2);	
    glVertex3d(x+robot_width/2, y+robot_height,  z-robot_length/2);	
    glEnd();
    
    glBegin(GL_POLYGON);
    glNormal3d(0.0,0.0,-1.0);  // esta normal fica comum aos 4 vertices
    glVertex3d(x+robot_width/2, y+robot_height,  z-robot_length/2);
    glVertex3d(x+robot_width/2, y,  z-robot_length/2);	
    glVertex3d(x-robot_width/2, y,  z-robot_length/2);   
    glVertex3d(x-robot_width/2, y+robot_height,  z-robot_length/2); 
    glEnd();
    
    //parede 1 end
    
    //Parede 2 begin
    glBegin(GL_POLYGON);
    glNormal3d(-1.0,0.0,0.0);  // esta normal fica comum aos 4 vertices
   
    glVertex3d(x-robot_width/2, y+robot_height,  z-robot_length/2); 
    glVertex3d(x-robot_width/2, y,  z-robot_length/2);   
    glVertex3d(x-robot_width/2, y,  z+robot_length/2);	
    glVertex3d(x-robot_width/2, y+robot_height,  z+robot_length/2);	
    glEnd();
    
      glBegin(GL_POLYGON);
    glNormal3d(1.0,0.0,0.0);  // esta normal fica comum aos 4 vertices
    glVertex3d(x-robot_width/2, y+robot_height,  z+robot_length/2);	
    glVertex3d(x-robot_width/2, y,  z+robot_length/2);	
    glVertex3d(x-robot_width/2, y,  z-robot_length/2); 
    glVertex3d(x-robot_width/2, y+robot_height,  z-robot_length/2); 
    glEnd();
    
    //parede 2 end
    
    //Parede 3 begin
    glBegin(GL_POLYGON);
    glNormal3d(0.0,0.0,1.0);  // esta normal fica comum aos 4 vertices
    glVertex3d(x-robot_width/2, y+robot_height,  z+robot_length/2); 
    glVertex3d(x-robot_width/2, y,  z+robot_length/2);   
    glVertex3d(x+robot_width/2, y,  z+robot_length/2);	
    glVertex3d(x+robot_width/2, y+robot_height,  z+robot_length/2);	
    glEnd();
    
    glBegin(GL_POLYGON);
    glNormal3d(0.0,0.0,-1.0);  // esta normal fica comum aos 4 vertices
    glVertex3d(x+robot_width/2, y+robot_height,  z+robot_length/2);
    glVertex3d(x+robot_width/2, y,  z+robot_length/2);	
    glVertex3d(x-robot_width/2, y,  z+robot_length/2);   
    glVertex3d(x-robot_width/2, y+robot_height,  z+robot_length/2); 
    glEnd();
    
    //parede 3 end
    
    
    
    //Parede 4 begin
    glBegin(GL_POLYGON);
    glNormal3d(-1.0,0.0,0.0);  // esta normal fica comum aos 4 vertices
    glVertex3d(x+robot_width/2, y+robot_height,  z-robot_length/2); 
    glVertex3d(x+robot_width/2, y,  z-robot_length/2);   
    glVertex3d(x+robot_width/2, y,  z+robot_length/2);	
    glVertex3d(x+robot_width/2, y+robot_height,  z+robot_length/2);	
    glEnd();
    
    glBegin(GL_POLYGON);
    glNormal3d(1.0,0.0,0.0);  // esta normal fica comum aos 4 vertices
    glVertex3d(x+robot_width/2, y+robot_height,  z+robot_length/2);	
    glVertex3d(x+robot_width/2, y,  z+robot_length/2);	
    glVertex3d(x+robot_width/2, y,  z-robot_length/2); 
    glVertex3d(x+robot_width/2, y+robot_height,  z-robot_length/2); 
    glEnd();
    
    //parede 4 end
    
    
    
    //fundo
    glBegin(GL_POLYGON);
    glNormal3d(0.0,1.0,0.0);  // esta normal fica comum aos 4 vertices
    glVertex3d(x-robot_width/2, y,  z-robot_length/2); 
    glVertex3d(x-robot_width/2, y,  z+robot_length/2);   
    glVertex3d(x+robot_width/2, y,  z+robot_length/2);	
    glVertex3d(x+robot_width/2, y,  z-robot_length/2);	
    glEnd();
    
    glBegin(GL_POLYGON);
    glNormal3d(0.0,-1.0,0.0);  // esta normal fica comum aos 4 vertices
   
    glVertex3d(x+robot_width/2, y,  z-robot_length/2);
    glVertex3d(x+robot_width/2, y,  z+robot_length/2);	
    glVertex3d(x-robot_width/2, y,  z+robot_length/2); 
    glVertex3d(x-robot_width/2, y,  z-robot_length/2); 
  
    
   
    glEnd();
    
    //fundo    
}