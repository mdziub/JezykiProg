#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

//============================================
// Definicje kolorow:

#define CZARN 0.0, 0.0, 0.0
#define CZERW 1.0, 0.0, 0.0
#define ZIELO 0.0, 1.0, 0.0
#define ZOLTY 1.0, 1.0, 0.0
#define NIEBI 0.0, 0.0, 1.0
#define MAGEN 1.0, 0.0, 1.0
#define CYJAN 0.0, 1.0, 1.0
#define BIALY 1.0, 1.0, 1.0

#define PI 3.1415926535897932384626433832795

//============================================
// Geometria obrazka:

void geom(int w, int h) {
  // Granice przedstawionego fragmentu przestrzeni:
  //   glOrtho(lewa, prawa, dolna, gorna, przednia, tylna);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-20, 20, -20, 20, -4, 4);
  glMatrixMode(GL_MODELVIEW);
}

void rysuj_wielokat(int n) {
  glColor3d(NIEBI);            // kolor
  glLineWidth(3.0);  

  glBegin(GL_POLYGON);
	for (int i=0; i<n; i++) {
		glVertex3f(5.0 * cos((PI/2 + 2*PI*i) / (float) n), 5.0 * sin((PI/2 + 2*PI*i) / (float) n), 0);
	}
  glEnd();
}

//============================================
// Scena:

void wyswietl(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  
  double x = -15.0;
  double y = 10.0;
  
  for (int i=0; i<3; i++) {
	  glPushMatrix();
	  glTranslated(x,y,0);
	  
	  rysuj_wielokat(5+i);	  
	  
	  glPopMatrix();
	  
	  x += 15.0;
  }
  
  x = -15.0;
  
  for (int i=0; i<3; i++) {
	  glPushMatrix();
	  glTranslated(x,0,0);
	  
	  rysuj_wielokat(8+i);	  
	  
	  glPopMatrix();
	  
	  x += 15.0;
	  
  }
  
  x = -15.0;
  
  for (int i=0; i<3; i++) {
	  glPushMatrix();
	  glTranslated(x,-10.0,0);
	  
	  rysuj_wielokat(11+i);	  
	  
	  glPopMatrix();
	  
	  x += 15.0;
  }
  
  glFlush();
}

//============================================

int main(int ile_arg, char* arg[]) {
  glutInit(&ile_arg, arg);
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(20, 10);
  glutCreateWindow(arg[0]);
  glClearColor(ZOLTY, 0.0);
  glutReshapeFunc(geom);
  glutDisplayFunc(wyswietl);
  glutMainLoop();
  return 0;
}
