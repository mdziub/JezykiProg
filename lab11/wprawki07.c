#include <GL/glut.h>

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

#define POMAR 1.0, 0.7, 0.0

//============================================
// Geometria obrazka:

void geom(int w, int h) {
  // Granice przedstawionego fragmentu przestrzeni:
  //   glOrtho(lewa, prawa, dolna, gorna, przednia, tylna);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0,2.4 , -1.2,1.2 , -1.2,1.2);
  glMatrixMode(GL_MODELVIEW);
}

//============================================
// Scena:

void kula(double x, double y, double z) {
  glPushMatrix();  glTranslated(x,y,z);
  glutSolidSphere(0.1,60,20);
  glPopMatrix();
}

void wyswietl(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

  glPointSize(50);

  glColor3d(CZARN); kula(-1,-1,-1);
  glColor3d(CZERW); kula( 1,-1,-1);
  glColor3d(ZIELO); kula(-1, 1,-1);
  glColor3d(POMAR); kula( 1, 1,-1);
  glColor3d(NIEBI); kula(-1,-1, 1);
  glColor3d(MAGEN); kula( 1,-1, 1);
  glColor3d(CYJAN); kula(-1, 1, 1);
  glColor3d(BIALY); kula( 1, 1, 1);

  glColor3d(CZARN);
  glBegin(GL_LINE_LOOP);
    glVertex3d(-1,-1,-1);
    glVertex3d( 1,-1,-1);
    glVertex3d( 1, 1,-1);
    glVertex3d(-1, 1,-1);
    glVertex3d(-1, 1, 1);
    glVertex3d( 1, 1, 1);
    glVertex3d( 1,-1, 1);
    glVertex3d(-1,-1, 1);
    glVertex3d(-1,-1,-1);
    glVertex3d(-1, 1,-1);
  glEnd();
  glBegin(GL_LINES);
    glVertex3d(-1,-1, 1); glVertex3d(-1, 1, 1);
    glVertex3d( 1, 1, 1); glVertex3d( 1, 1,-1);
    glVertex3d( 1,-1, 1); glVertex3d( 1,-1,-1);
  glEnd();

  glFlush();
}

//============================================

int main(int ile_arg, char* arg[]) {
  glutInit(&ile_arg, arg);
  glutInitWindowSize(400, 300);
  glutInitWindowPosition(20, 10);
  glutCreateWindow(arg[0]);
  glClearColor(ZOLTY, 0.0);
  glutReshapeFunc(geom);
  glutDisplayFunc(wyswietl);
  glutMainLoop();
  return 0;
}
