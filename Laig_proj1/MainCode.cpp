// G1_Ilum.cpp : Defines the entry point for the console application.
//

#ifdef __APPLE__
#include <GLUI/GLUI.h>
#else
#include <gl\glui.h>
#endif

#include <math.h>
#include "RGBpixmap.h"
#include "Room.h"
#include "Robot.h"
#include "PaperSheet.h"

// quadricas
GLUquadric* glQ;	// nec. p/ criar sup. quadraticas (cilindros, esferas...)


// dimensoes e localizacao da janela
#define DIMX 500
#define DIMY 500
#define INITIALPOS_X 200
#define INITIALPOS_Y 200

const int TRUE  = 1;
const int FALSE = 0;

float xy_aspect;

// matriz de transf. geometrica utilizada pelo botao esferico
float view_rotate[16] = { 1,0,0,0,
                          0,1,0,0,
                          0,0,1,0,
                          0,0,0,1 };

// vector de posicao utilizado pelo botao de afastamento
float obj_pos[] = { 0.0, 0.0, 0.0 };

// declarações para os tres eixos (cilindros)
double axis_radius_begin =  0.4;
double axis_radius_end   =  0.0;
double axis_lenght       = 32.0;
int axis_nslices = 8;
int axis_nstacks = 1;

// declaracoes para as paredes
float mat1_shininess[] = {128.0}; 
float mat1_specular[] = {0.3, 0.3, 0.3, 1.0};	/* specular reflection. */
float mat1_diffuse[] =  {0.7, 0.7, 0.7, 1.0};	/* diffuse reflection. */
float mat1_ambient[] =  {0.7, 0.7, 0.7, 1.0};	/* ambient reflection. */

float roomX = 30;  /* metade... */
float roomY = 35;
float roomZ = 115;  /* metade... */

// declarações para a fonte de luz LIGHT0;
float light0_position[]  = {0.0, 3.0, 4.0, 1.0}; // nao necessaria...
float light0_ambient[] =   {0.0, 0.0, 0.0, 1.0}; // sem componente ambiente
float light0_diffuse[] =   {6.0, 6.0, 6.0, 1.0};
float light0_specular[] =  {6.0, 6.0, 6.0, 1.0};
float light0_kc = 0.0;
float light0_kl = 1.0;
float light0_kq = 0.0;
double light0x = 5.0;
double light0y = 4;
double light0z = 10.0;
double symb_light0_radius = 0.2;
int symb_light0_slices = 8;
int symb_light0_stacks =8;

// fonte (global) de luz ambiente 
float light_ambient[] = {0.6, 0.6, 0.6, 1.0}; /* Set the background ambient lighting. */


// variaveis para a janela
int main_window;
GLUI  *glui2;


RGBpixmap pixmap;




void display(void)
{
	// ****** declaracoes internas 'a funcao display() ******
	
	float temp;

	// ****** fim de todas as declaracoes da funcao display() ******


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
	// inicializacoes da matriz de visualizacao
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glFrustum( -xy_aspect*.04, xy_aspect*.04, -.04, .04, .1, 500.0 );

	//inicializacoes da matriz de transformacoes geometricas
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	
	// afasta a cena de 70 unidades mais a distância que...
	// ...decorre da utilizacao do botao de afastamento (pseudo-zoom)
    glTranslatef( obj_pos[0], obj_pos[1], -obj_pos[2]-70 );
		// tambem se poderia ter feito:
		//glTranslated(0.0,0.0,-70.0);
		//glTranslatef( obj_pos[0], obj_pos[1], -obj_pos[2] );

	// roda a cena para ficar em perspectiva
	glRotated( 20.0, 1.0,0.0,0.0 );		// 20 graus em torno de X
	glRotated(-10.0, 0.0,1.0,0.0 );		//-10 graus em torno de Y

	// roda a cena de acordo com o botao (esfera) de rotacao
	glMultMatrixf( view_rotate );

	// permissao de atribuicao directa de cores
	// para objectos que nao tem material atribuido, como
	// e' o caso dos eixos e da esfera que simboliza a fonte de luz...
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	// cilindro representativo do eixo X
	glColor3f(1.0,0.0,0.0);		// vermelho
	glPushMatrix();
	glRotated(90.0, 0.0,1.0,0.0 );
	gluCylinder(glQ, axis_radius_begin, axis_radius_end,
		             axis_lenght, axis_nslices, axis_nstacks);   // nao tem bases
	
	glPopMatrix();

	// cilindro representativo do eixo Y
	glColor3f(0.0,1.0,0.0);		// verde
	glPushMatrix();
	glRotated(-90.0, 1.0,0.0,0.0 );
	gluCylinder(glQ, axis_radius_begin, axis_radius_end,
		             axis_lenght, axis_nslices, axis_nstacks);   // nao tem bases
	
	glPopMatrix();
	
	// cilindro representativo do eixo Z
	glColor3f(0.0,0.0,1.0);		// azul
	glPushMatrix();
	// nao necessita rotacao... glRotated(...);
	gluCylinder(glQ, axis_radius_begin, axis_radius_end,
		             axis_lenght, axis_nslices, axis_nstacks);   // nao tem bases
	
	glPopMatrix();

	
	// Actualizacao da posicao da fonte de luz...
	light0_position[0] = light0x;	// por razoes de eficiencia, os restantes 
	light0_position[1] = light0y;	// parametros _invariaveis_ da LIGHT0 mantem os valores
	light0_position[2] = light0z;	// definidos na funcao de inicializacao
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

	// ... e da esfera que a simboliza
	glColor3f(1.0,1.0,0.0);		// cor amarela
	gluQuadricOrientation( glQ, GLU_INSIDE);
	glPushMatrix();
	glTranslated(light0x,light0y,light0z);
	gluSphere(glQ, symb_light0_radius, symb_light0_slices, symb_light0_stacks);
    glPopMatrix();
	gluQuadricOrientation( glQ, GLU_OUTSIDE);


	glDisable(GL_COLOR_MATERIAL);
	// Definicao de material a usar daqui em diante (valores declarados acima)
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat1_shininess);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  mat1_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,   mat1_diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,   mat1_ambient);

	// desenha rectangulo paralelo ao plano XY, com texturas
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 1);	// activa a textura 1 (feup)
	temp = 2; // duas repetições na direccao Z
	/*
	glBegin(GL_POLYGON);
		glNormal3d(0.0,0.0,1.0);  // esta normal fica comum aos 4 vertices
		glTexCoord2f(0.0,0.0);  glVertex3d(-roomX, 0.0, roomZ);	// associacao de
		glTexCoord2f(1.0,0.0);  glVertex3d(roomX, 0.0, roomZ);	// coordenadas u,v
		glTexCoord2f(1.0,temp); glVertex3d(roomX, 0.0,  -roomZ);	// das texturas, aos
		glTexCoord2f(0.0,temp); glVertex3d(-roomX, 0.0,  -roomZ);	// vertices 3D do poligono
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, 3);
	glBegin(GL_POLYGON);
		glNormal3d(0.0,-1.0,0.0);  // esta normal fica comum aos 4 vertices
		glTexCoord2f(0.0,0.0);  glVertex3d(-roomX, roomY, roomZ);	// associacao de
		glTexCoord2f(1.0,0.0);  glVertex3d(roomX, roomY, roomZ);	// coordenadas u,v
		glTexCoord2f(1.0,temp); glVertex3d(roomX, roomY,  -roomZ);	// das texturas, aos
		glTexCoord2f(0.0,temp); glVertex3d(-roomX, roomY,  -roomZ);	// vertices 3D do poligono
	glEnd();
	*/
	// desenha rectangulo paralelo ao plano ZY, sem texturas
	glDisable(GL_TEXTURE_2D);/*
	glBegin(GL_POLYGON);
		glNormal3d(1.0,0.0,0.0);  // esta normal fica comum aos 4 vertices
		glVertex3d( -roomX, 0.0,  roomZ);
		glVertex3d(-roomX, 0.0,  -roomZ);
		glVertex3d(-roomX, roomY,  -roomZ);
		glVertex3d( -roomX, roomY,  roomZ);
	glEnd();

	glEnable(GL_COLOR_MATERIAL);
	glColor3f(1.0,0.0,1.0);	
	glBegin(GL_POLYGON);
		glNormal3d(0.0,0.0,1.0);  // esta normal fica comum aos 4 vertices
		glTexCoord2f(0.0,0.0);  glVertex3d(-roomX, 0.0, -roomZ);	// associacao de
		glTexCoord2f(1.0,0.0);  glVertex3d(roomX, 0.0, -roomZ);	// coordenadas u,v
		glTexCoord2f(1.0,temp); glVertex3d(roomX, roomY,  -roomZ);	// das texturas, aos
		glTexCoord2f(0.0,temp); glVertex3d(-roomX, roomY,  -roomZ);	// vertices 3D do poligono
	glEnd();

	glEnable(GL_COLOR_MATERIAL);
	glColor3f(1.0,1.0,0.0);	
	glBegin(GL_POLYGON);
		glNormal3d(0.0,0.0,1.0);  // esta normal fica comum aos 4 vertices
		glTexCoord2f(0.0,0.0);  glVertex3d(roomX, 0.0, -roomZ);	// associacao de
		glTexCoord2f(1.0,0.0);  glVertex3d(roomX, 0.0, roomZ);	// coordenadas u,v
		glTexCoord2f(1.0,temp); glVertex3d(roomX, roomY,  roomZ);	// das texturas, aos
		glTexCoord2f(0.0,temp); glVertex3d(roomX, roomY,  -roomZ);	// vertices 3D do poligono
	glEnd();

	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.0,1.0,0.0);	
	glBegin(GL_POLYGON);
		glNormal3d(0.0,0.0,1.0);  // esta normal fica comum aos 4 vertices
		glTexCoord2f(0.0,0.0);  glVertex3d(roomX, 0.0, roomZ);	// associacao de
		glTexCoord2f(1.0,0.0);  glVertex3d(roomX, roomY, roomZ);	// coordenadas u,v
		glTexCoord2f(1.0,temp); glVertex3d(-roomX, roomY,  roomZ);	// das texturas, aos
		glTexCoord2f(0.0,temp); glVertex3d(-roomX, 0.0,  roomZ);	// vertices 3D do poligono
	glEnd();
	*/
	
	draw_room(0.0,0.0,0.0);
    draw_robot(0.0, 0.0, 0.0);
	draw_machine(-5.0, 0.0, 0.0);


	// swapping the buffers causes the rendering above to be shown
	glutSwapBuffers();
	// glFlush(); included in the above glutSwapBuffers()
}


/* Mouse handling */
void processMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{	 
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{	
	}
	
	glutPostRedisplay();
	
}

void processMouseMoved(int x, int y)
{
	
	// pedido de refrescamento da janela
	glutPostRedisplay();				

}

void processPassiveMouseMoved(int x, int y)
{

	// pedido de refrescamento da janela
	glutPostRedisplay();				
}

void reshape(int w, int h)
{
	int tx, ty, tw, th;

	GLUI_Master.get_viewport_area( &tx, &ty, &tw, &th );
	glViewport( tx, ty, tw, th );
	xy_aspect = (float)tw / (float)th;

	glutPostRedisplay();

}


void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
    case 27:		// tecla de escape termina o programa
         exit(0);
         break;
	case 'w':
		  light0y++;
		break;
	case 's':
		  light0y--;
		  break;
	case 'a':
		  light0x--;
		  break;
	case 'd':
		  light0x++;
		  break;
	case 'r':
		  light0z--;
		  break;	
	case 'f':
		  light0z++;
		  break;
   }
}


void myGlutIdle( void )
{
  /* According to the GLUT specification, the current window is 
     undefined during an idle callback.  So we need to explicitly change
     it if necessary */
  if ( glutGetWindow() != main_window ) 
    glutSetWindow(main_window);  


  glutPostRedisplay();

}

void inicializacao()
{

	// inicialização de apontador para quádricas
	glQ = gluNewQuadric();


	glFrontFace(GL_CCW);		// Front faces defined using a counterclockwise rotation
	glDepthFunc(GL_LEQUAL);		// Por defeito e GL_LESS
	glEnable(GL_DEPTH_TEST);	// Use a depth (z) buffer to draw only visible objects


	// Face Culling para aumentar a velocidade
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);		// GL_FRONT, GL_BACK, GL_FRONT_AND_BACK


	// Define que modelo de iluminacao utilizar; consultar o manual de referencia
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, light_ambient);  // define luz ambiente
	glLightModelf (GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
	glLightModeli (GL_LIGHT_MODEL_LOCAL_VIEWER, 1);
	
	// por defeito a cor de fundo e o preto
	// glClearColor(1.0,1.0,1.0,1.0);    // cor de fundo a branco


	// declaracoes para a fonte luz GL_LIGHT0
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION,  light0_kc);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION,    light0_kl);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, light0_kq);

	// NOTA: a direccao e a posicao de GL_LIGHT0 estao na rotina display(), pelo
	//       que as isntrucoes seguntes nao sao necessarias
	//glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 90.0);
	//glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
	//glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

	// Permitir calculos de iluminacao
	glEnable(GL_LIGHTING);
	// "Acender" a fonte de luz GL_LIGHT0
	glEnable(GL_LIGHT0);


	// Declaracoe para shading
	glShadeModel(GL_SMOOTH);			// GL_FLAT / GL_SMOOTH
	glPolygonMode(GL_FRONT, GL_FILL);	// preence a face da frente dos poligonos
	// glPolygonMode(GL_FRONT, GL_LINE);	// desenha arestas dos poligonos


	// Texturas a utilizar (ver classe RGBpixmap)
	pixmap.readBMPFile("feup.bmp");
	pixmap.setTexture(1);

	pixmap.readBMPFile("tile.bmp");
	pixmap.setTexture(2);

	pixmap.readBMPFile("clamp.bmp");
	pixmap.setTexture(3);

	pixmap.readBMPFile("mandril.bmp");
	pixmap.setTexture(4);

	pixmap.readBMPFile("paisagem.bmp");
	pixmap.setTexture(5);

	pixmap.readBMPFile("wall_tex.bmp");
	pixmap.setTexture(6);
}

void terminacao()
{
	gluDeleteQuadric(glQ);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize (DIMX, DIMY);
	glutInitWindowPosition (INITIALPOS_X, INITIALPOS_Y);
	main_window = glutCreateWindow (argv[0]);
 
	glutDisplayFunc(display);
	GLUI_Master.set_glutReshapeFunc(reshape);
	GLUI_Master.set_glutKeyboardFunc (keyboard);
	GLUI_Master.set_glutMouseFunc(processMouse);
	glutMotionFunc(processMouseMoved);
	glutPassiveMotionFunc(processPassiveMouseMoved);
	GLUI_Master.set_glutSpecialFunc( NULL );
   

	/*** Create the bottom subwindow ***/
	glui2 = GLUI_Master.create_glui_subwindow( main_window, GLUI_SUBWINDOW_BOTTOM );
	glui2->set_main_gfx_window( main_window );

	GLUI_Rotation *view_rot = glui2->add_rotation( "Rotacao", view_rotate );
	view_rot->set_spin( 1.0 );
	
	glui2->add_column( false );
	GLUI_Translation *trans_z = glui2->add_translation( "Zoom", GLUI_TRANSLATION_Z, &obj_pos[2] );
	trans_z->set_speed( .10 );


	/* We register the idle callback with GLUI, not with GLUT */
	GLUI_Master.set_glutIdleFunc( myGlutIdle );
   
	inicializacao();
   
	glutMainLoop();

	terminacao();

	return 0;
}