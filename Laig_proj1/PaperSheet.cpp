#include "PaperSheet.h"

double carpet_height = 3;
double carpet_width = 5;
double carpet_long = 36;
double cylinder_diameter = 2.0;
double machine_side_size = 8;
double machine_extra_size = 3;
double machine_top_height = 2;
double teapot_height = 2;
double guill_position = 2*carpet_long/3;
double guill_side_size = carpet_width/15;
double guill_top_height = cylinder_diameter + 0.5;
double guill_bottom_height = 0.8;

void myBox(double dx, double dy, double dz)

// desenha um paralelepipedo _centrado_na_origem_, com
// dimensoes dx, dy, dz;

{
	dx/=2.0; dy/=2.0; dz/=2.0;

	// estao a faltar 4 faces...

	//face da esquerda
	glBegin(GL_POLYGON);
 	    glNormal3d(-1.0,0.0,0.0);
		glVertex3d(-dx,-dy,dz);
		glVertex3d(-dx,dy,dz);
		glVertex3d(-dx,dy,-dz);
		glVertex3d(-dx,-dy,-dz);

	glEnd();

	//face de cima
	glBegin(GL_POLYGON);
	    glNormal3d(0.0,1.0,0.0);
		glVertex3d(dx,dy,dz);
		glVertex3d(dx,dy,-dz);
		glVertex3d(-dx,dy,-dz);
		glVertex3d(-dx,dy,dz);
	glEnd();

	//face da direita
	glBegin(GL_POLYGON);
 	    glNormal3d(1.0,0.0,0.0);
		glVertex3d(dx,-dy,-dz);
		glVertex3d(dx,dy,-dz);
		glVertex3d(dx,dy,dz);
		glVertex3d(dx,-dy,dz);
	glEnd();

	//face de baixo
	glBegin(GL_POLYGON);
	    glNormal3d(0.0,-1.0,0.0);
		glVertex3d(-dx,-dy,dz);
		glVertex3d(-dx,-dy,-dz);
		glVertex3d(dx,-dy,-dz);
		glVertex3d(dx,-dy,dz);



	glEnd();

	//face da frente
	glBegin(GL_POLYGON);
		glNormal3d(0.0,0.0,1.0);
		glVertex3d(-dx,dy,dz);
		glVertex3d(-dx,-dy,dz);
		glVertex3d(dx,-dy,dz);
		glVertex3d(dx,dy,dz);



	glEnd();

	//face de tras
	glBegin(GL_POLYGON);
		glNormal3d(0.0,0.0,-1.0);
		glVertex3d(dx,dy,-dz);
		glVertex3d(dx,-dy,-dz);
		glVertex3d(-dx,-dy,-dz);
		glVertex3d(-dx,dy,-dz);
	glEnd();
}


void draw_machine(double x, double y, double z){
	glEnable(GL_NORMALIZE);
    glPushMatrix();
	draw_carpet(x,y,z);
	draw_printer(x,y,z);
	draw_teapot(x,y,z);
	draw_guillotine_sides(x,y,z);
	glPopMatrix();
    glDisable(GL_NORMALIZE);
}

void draw_machine_animation(double x, double y, double z){
	draw_printer_cylinder(x,y,z);
	draw_guillotine(x,y,z);
}

void draw_carpet(double x, double y, double z){
	glPushMatrix();
	glTranslated(0.0, 0.0, -20.0);
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 7);
    glBegin(GL_POLYGON);
	glNormal3d(0.0,0.0,1.0);
	glTexCoord2f(0.0,2.0); glVertex3d(x-carpet_width, y+carpet_height, z+carpet_long);
	glTexCoord2f(0.0,0.0); glVertex3d(x-carpet_width, y ,z+carpet_long);
	glTexCoord2f(2.0,0.0); glVertex3d(x,y,z+ carpet_long);
	glTexCoord2f(2.0,2.0); glVertex3d(x,y+carpet_height,z+carpet_long);
	glEnd();
    glDisable(GL_TEXTURE_2D);
	// parte da esquerda da linha de impressão
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 7);
	glBegin(GL_POLYGON);
	glNormal3d(-1.0,0.0,0.0);
	glTexCoord2d(0.0, 2.0);glVertex3d(x-carpet_width, y+carpet_height, z);
	glTexCoord2d(0.0, 0.0);glVertex3d(x-carpet_width, y, z);
	glTexCoord2d(2.0, 0.0);glVertex3d(x-carpet_width, y, z+carpet_long);
	glTexCoord2d(2.0, 2.0);glVertex3d(x-carpet_width, y+carpet_height, z+carpet_long);
	glEnd();
    glDisable(GL_TEXTURE_2D);
	//parte da direita da linha de impressao
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 7);
	glBegin(GL_POLYGON);
	glNormal3d(1.0, 0.0,0.0);
	glTexCoord2d(0.0, 2.0);glVertex3d(x, y+carpet_height, z+carpet_long);
	glTexCoord2d(0.0,0.0);glVertex3d(x, y, z+carpet_long);
	glTexCoord2d(2.0, 0.0);glVertex3d(x, y, z);
	glTexCoord2d(2.0, 2.0);glVertex3d(x, y+carpet_height, z);
	glEnd();
    glDisable(GL_TEXTURE_2D);
	//parte de tras
	glBegin(GL_POLYGON);
		glNormal3d(0.0,0.0,-1.0);
		glVertex3d(x-carpet_width, y+carpet_height, z);
		glVertex3d(x-carpet_width, y ,z);
		glVertex3d(x,y,z);
		glVertex3d(x,y+carpet_height,z);
	glEnd();

	//parte de cima - TODO aplicar textura

	glBegin(GL_POLYGON);
		glNormal3d(0.0,1.0,0.0);
		glVertex3d(x-carpet_width, y+carpet_height, z+carpet_long);
		glVertex3d(x, y+carpet_height, z+carpet_long);
		glVertex3d(x, y+carpet_height, z);
		glVertex3d(x-carpet_width, y+carpet_height, z);
	glEnd();

	//parte de baixo

	glBegin(GL_POLYGON);
		glNormal3d(0.0,-1.0,0.0);
		glVertex3d(x-carpet_width, y, z+carpet_long);
		glVertex3d(x, y, z+carpet_long);
		glVertex3d(x, y, z);
		glVertex3d(x-carpet_width, y, z);
	glEnd();
    
	glPopMatrix();
}

void draw_printer(double x, double y, double z){
	glPushMatrix();
	glTranslated(0.0, 0.0, -20.0);
	//parte de cima
	glBegin(GL_POLYGON);
		glNormal3d(0.0, 1.0, 0.0);
		glVertex3d(x-carpet_width-machine_extra_size, y+carpet_height+cylinder_diameter+machine_top_height, z+cylinder_diameter-machine_side_size);
		glVertex3d(x-carpet_width-machine_extra_size, y+carpet_height+cylinder_diameter+machine_top_height, z+cylinder_diameter);
		glVertex3d(x+machine_extra_size, y+carpet_height+cylinder_diameter+machine_top_height, z+cylinder_diameter);
		glVertex3d(x+machine_extra_size, y+carpet_height+cylinder_diameter+machine_top_height, z+cylinder_diameter-machine_side_size);
	glEnd();

	//parte de baixo
	glBegin(GL_POLYGON);
			glNormal3d(0.0, -1.0, 0.0);
			glVertex3d(x-carpet_width-machine_extra_size, y, z+cylinder_diameter-machine_side_size);
			glVertex3d(x-carpet_width-machine_extra_size, y, z+cylinder_diameter);
			glVertex3d(x+machine_extra_size, y, z+cylinder_diameter);
			glVertex3d(x+machine_extra_size, y, z+cylinder_diameter-machine_side_size);
		glEnd();

	//Parte de tras

	glBegin(GL_POLYGON);
	glNormal3d(0.0,0.0,-1.0);



	glVertex3d(x+machine_extra_size, y+carpet_height+cylinder_diameter+machine_top_height, z+cylinder_diameter-machine_side_size);
	glVertex3d(x+machine_extra_size, y, z+cylinder_diameter-machine_side_size);
	glVertex3d(x-carpet_width-machine_extra_size, y, z+cylinder_diameter-machine_side_size);
	glVertex3d(x-carpet_width-machine_extra_size, y+carpet_height+cylinder_diameter+machine_top_height, z+cylinder_diameter-machine_side_size);
	glEnd();

	//lado esquerdo
	glBegin(GL_POLYGON);
		glNormal3d(-1.0,0.0,0.0);
		glVertex3d(x-carpet_width-machine_extra_size, y+carpet_height+cylinder_diameter+machine_top_height, z+cylinder_diameter-machine_side_size);
		glVertex3d(x-carpet_width-machine_extra_size, y, z+cylinder_diameter-machine_side_size);
		glVertex3d(x-carpet_width-machine_extra_size, y, z+cylinder_diameter);
		glVertex3d(x-carpet_width-machine_extra_size, y+carpet_height+cylinder_diameter+machine_top_height, z+cylinder_diameter);
	glEnd();

	//lado direito
	glBegin(GL_POLYGON);
		glNormal3d(1.0,0.0,0.0);
		glVertex3d(x+machine_extra_size, y+carpet_height+cylinder_diameter+machine_top_height, z+cylinder_diameter-machine_side_size);
		glVertex3d(x+machine_extra_size, y+carpet_height+cylinder_diameter+machine_top_height, z+cylinder_diameter);
		glVertex3d(x+machine_extra_size, y, z+cylinder_diameter);
		glVertex3d(x+machine_extra_size, y, z+cylinder_diameter-machine_side_size);
	glEnd();

	//partes de frente/lado
	glBegin(GL_POLYGON);
	glNormal3d(0.0,0.0,1.0);
	glVertex3d(x-carpet_width-machine_extra_size, y+carpet_height+cylinder_diameter+machine_top_height, z+cylinder_diameter);
	glVertex3d(x-carpet_width-machine_extra_size, y, z+cylinder_diameter);
	glVertex3d(x-carpet_width, y, z+cylinder_diameter);
	glVertex3d(x-carpet_width, y+carpet_height+cylinder_diameter+machine_top_height, z+cylinder_diameter);
	glEnd();

	glBegin(GL_POLYGON);
		glNormal3d(0.0,0.0,1.0);
		glVertex3d(x, y+carpet_height+cylinder_diameter+machine_top_height, z+cylinder_diameter);
		glVertex3d(x, y, z+cylinder_diameter);
		glVertex3d(x+machine_extra_size, y, z+cylinder_diameter);
		glVertex3d(x+machine_extra_size, y+carpet_height+cylinder_diameter+machine_top_height, z+cylinder_diameter);
	glEnd();

	//parte de frente/cima

	glBegin(GL_POLYGON);
			glNormal3d(0.0,0.0,1.0);
			glVertex3d(x-carpet_width, y+carpet_height+cylinder_diameter+machine_top_height, z+cylinder_diameter);
			glVertex3d(x-carpet_width, y+carpet_height+cylinder_diameter, z+cylinder_diameter);
			glVertex3d(x, y+carpet_height+cylinder_diameter, z+cylinder_diameter);
			glVertex3d(x, y+carpet_height+cylinder_diameter+machine_top_height, z+cylinder_diameter);
	glEnd();
	glPopMatrix();

}

void draw_printer_cylinder(double x, double y, double z){
		//cilindro
		glPushMatrix();
		glTranslated(0.0, 0.0, -20.0);
			glDisable( GL_CULL_FACE );
			GLUquadric *w1;
			    w1=gluNewQuadric();

			    glTranslated(x-carpet_width, y+(cylinder_diameter/2)+carpet_height,z+(cylinder_diameter));
			    glRotated(90,0,1,0);


			    glPushMatrix();
			    gluDisk(w1, 0.0, cylinder_diameter/2, 10, 1);
			    glPopMatrix();
			    glPushMatrix();
			    glTranslated(0.0, 0.0, carpet_width);
			    gluDisk(w1, 0.0, cylinder_diameter/2, 10, 1);
			    glPopMatrix();
			    glPushMatrix();
			    gluCylinder(w1, cylinder_diameter/2, cylinder_diameter/2, carpet_width, 10, 1);
			    glPopMatrix();
			    glEnable( GL_CULL_FACE );
			    glCullFace(GL_BACK);
			glPopMatrix();
	}

void draw_teapot(double x, double y, double z){
	glPushMatrix();
	glTranslated(0.0, 0.0, -20.0);
	glTranslated(x-teapot_height,y+carpet_height+cylinder_diameter+machine_top_height+teapot_height/2,z-teapot_height/2);
	glutSolidTeapot(teapot_height);
	glPopMatrix();
}

void draw_guillotine_sides(double x, double y, double z){
	//Partes de lado

	glPushMatrix();
		glTranslated(x-carpet_width+guill_side_size/2, y+carpet_height+1, z+guill_position);
		glTranslated(0.0, 0.0, -20.0);
		myBox(guill_side_size, 4, guill_side_size);
	glPopMatrix();

	glPushMatrix();
		glTranslated(x-guill_side_size/2, y+carpet_height+1, z+guill_position);
		glTranslated(0.0, 0.0, -20.0);
		myBox(guill_side_size, 4, guill_side_size);
	glPopMatrix();
}

void draw_guillotine(double x, double y, double z){
	glPushMatrix();
	glTranslated(0.0, 0.0, -20.0);
	glDisable( GL_CULL_FACE );
	glBegin(GL_POLYGON);
	glNormal3d(0.0,0.0,1.0);
	glVertex3d(x-carpet_width+guill_side_size, y+carpet_height+guill_top_height, z+guill_position);
	glVertex3d(x-carpet_width+guill_side_size, y+carpet_height+guill_bottom_height, z+guill_position);
	glVertex3d(x-guill_side_size, y+carpet_height+guill_bottom_height, z+guill_position);
	glVertex3d(x-guill_side_size, y+carpet_height+guill_top_height, z+guill_position);
	glEnd();
	glEnable( GL_CULL_FACE );
	glCullFace(GL_BACK);
	glPopMatrix();
}
