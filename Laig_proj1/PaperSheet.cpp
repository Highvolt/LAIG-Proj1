#include "PaperSheet.h"

double carpet_height = 3;
double carpet_width = 5;
double carpet_long = 30;

void draw_machine(double x, double y, double z){
	draw_carpet(x,y,z);
}

void draw_carpet(double x, double y, double z){
	//parte da linha de impressao paralela à parede do fundo
	glTranslated(0.0, 0.0, -20.0);
	glBegin(GL_POLYGON);
	glNormal3d(0.0,0.0,1.0);
	glVertex3d(x-carpet_width, y+carpet_height, z+carpet_long);
	glVertex3d(x-carpet_width, y ,z+carpet_long);
	glVertex3d(x,y,z+ carpet_long);
	glVertex3d(x,y+carpet_height,z+carpet_long);
	glEnd();

	// parte da esquerda da linha de impressão

	glBegin(GL_POLYGON);
	glNormal3d(-1.0,0.0,0.0);
	glVertex3d(x-carpet_width, y+carpet_height, z);
	glVertex3d(x-carpet_width, y, z);
	glVertex3d(x-carpet_width, y, z+carpet_long);
	glVertex3d(x-carpet_width, y+carpet_height, z+carpet_long);
	glEnd();

	//parte da direita da linha de impressao

	glBegin(GL_POLYGON);
	glNormal3d(1.0, 0.0,0.0);
	glVertex3d(x, y+carpet_height, z+carpet_long);
	glVertex3d(x, y, z+carpet_long);
	glVertex3d(x, y, z);
	glVertex3d(x, y+carpet_height, z);
	glEnd();

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
}
