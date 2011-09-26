#include "Robot.h"

double robot_width=4;
double robot_length=4;
double robot_height=4;
double rims_size=4;
double rims_width=2;
void draw_robot(double x, double y, double z){
    draw_box(x,y , z);
    draw_wheels(x,y,z);
    
}

void draw_wheels(double x,double y,double z){
    glPushMatrix();
    glDisable( GL_CULL_FACE );
    glRotated(90.0, 1.0, 0.0, 0.0);
    glTranslated(x+robot_width/2-rims_size/2, y+rims_size, z+rims_width);
    GLUquadric *w1;
    w1=gluNewQuadric();
    gluCylinder(w1, rims_size, rims_size, rims_width, 10, 1);
   
    glEnable( GL_CULL_FACE );
    glCullFace(GL_BACK);
    glPopMatrix();

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