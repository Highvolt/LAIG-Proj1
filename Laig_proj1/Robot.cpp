#include "Robot.h"

double robot_width=5.5;
double robot_length=5.5;
double robot_height=2;
double rims_size=1;
double rims_width=0.2;
double candle_height=9;
double candle_radius=0.5;

void draw_robot(double x, double y, double z){
    draw_box(x,y+rims_size/2 , z);
    draw_wheels(x,y,z);
	draw_candle(x+robot_width/2-candle_radius/2,y+robot_height+rims_size/2,z);
    
}

void draw_candle(double x, double y, double z){

    double plane[]={0,1,0,0};
    glPushMatrix();
	glEnable(GL_NORMALIZE);
	glTranslated(x,y,z);
	glScaled(0.5,0.5,0.5);
	
    glTranslated(0, 10, 0);
    glPushMatrix();
    glTranslated(1.0, 0, 0);
    glClipPlane(GL_CLIP_PLANE0, plane);
    
    glEnable(GL_CLIP_PLANE0);
    glutSolidTorus(0.5,1.0,10,10);
    glDisable(GL_CLIP_PLANE0);
    GLUquadric* a=gluNewQuadric();
    glPopMatrix();
    glPushMatrix();
    glRotated(90, 1, 0, 0);
    gluCylinder(a, 0.5, 0.5, 10, 10, 10);
	glDisable(GL_NORMALIZE);
    glPopMatrix();
    glPopMatrix();
    
}

void draw_wheel(){
    GLUquadric *w1;
    w1=gluNewQuadric();
    
    glPushMatrix();
    gluDisk(w1, 0.0, rims_size, 10, 1);
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.0,  0.0,rims_width);
    gluDisk(w1, 0.0, rims_size, 10, 1);
    glPopMatrix();
    glPushMatrix();
    gluCylinder(w1, rims_size, rims_size, rims_width, 10, 1);
    glPopMatrix();
}

void draw_wheels(double x,double y,double z){
   glDisable( GL_CULL_FACE );
    /*  glRotated(90.0, 1.0, 0.0, 0.0);*/
   //double rims_size=0;
    glPushMatrix();
    glTranslated(x+robot_width/2-rims_size/2, y+rims_size, z+robot_length/2);
    draw_wheel();
    glPopMatrix();
    glPushMatrix();
    glTranslated(x-robot_width/2+rims_size/2, y+rims_size, z+robot_length/2);
    draw_wheel();
    glPopMatrix();
    glPushMatrix();
    glTranslated(x+robot_width/2-rims_size/2, y+rims_size, z-robot_length/2-rims_width);
    draw_wheel();
    glPopMatrix();
    glPushMatrix();
    glTranslated(x-robot_width/2+rims_size/2, y+rims_size, z-robot_length/2-rims_width);
    draw_wheel();
    glPopMatrix();
    glEnable( GL_CULL_FACE );
    glCullFace(GL_BACK);


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
