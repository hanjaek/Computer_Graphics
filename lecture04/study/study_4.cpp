#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

#define GL_PI 3.141592f 
void glPointSize(GLfloat s);
void glLineWidth(GLfloat ls);

float getRandomFloat() {
   return (float)rand() / (float)RAND_MAX;
}

GLfloat xTran = 0.0f;
GLfloat yTran = 0.0f;

void keyboard(unsigned char key, int x, int y) {
   if (key == 'a') {
      xTran -= 2.0f;
   }
   else if (key == 'd') {
      xTran += 2.0f;
   }
   else if (key == 'w') {
      yTran += 2.0f;
   }
   else if (key == 'x') {
      yTran -= 2.0f;
   }
   glutPostRedisplay();
}

GLfloat xRot = 0.0f;
GLfloat yRot = 0.0f;
void SpecialKeys(int key, int x, int y) {
   if (key == GLUT_KEY_UP)
      xRot -= 2.0f;
   else if (key == GLUT_KEY_DOWN)
      xRot += 2.0f;
   else if (key == GLUT_KEY_LEFT)
      yRot -= 2.0f;
   else if (key == GLUT_KEY_RIGHT)
      yRot += 2.0f;
   glutPostRedisplay();
}
void RenderScene(void)
{
   bool bCull = true;
   glClear(GL_COLOR_BUFFER_BIT);

   if (bCull)
      glEnable(GL_CULL_FACE);
   else
      glDisable(GL_CULL_FACE);

   // 원뿔을 점선으로 그리기
   glPushMatrix();
   glRotatef(xRot, 1.0f, 0.0f, 0.0f);
   glRotatef(yRot, 0.0f, 1.0f, 0.0f);
   glTranslatef(xTran, yTran, 0.0f);

   GLfloat angle, x, y;
   GLfloat radius = 50.0f;
   GLfloat height = 100.0f;

   glEnable(GL_LINE_STIPPLE);
   glLineStipple(1, 0x0F0F);  // 점선 패턴

   // [1] 밑면 원판 (z = 0)
   glBegin(GL_LINES);
   for (angle = 0.0f; angle < 2 * GL_PI; angle += (GL_PI / 64.0f)) {
      x = radius * cos(angle);
      y = radius * sin(angle);
      glVertex3f(x, y, 0.0f);
   }
   glEnd();

   // [2] 옆면 (중심점과 밑면 외곽을 연결)
   glBegin(GL_LINES);
   for (angle = 0.0f; angle < 2 * GL_PI; angle += (GL_PI / 16.0f)) {
      x = radius * cos(angle);
      y = radius * sin(angle);
      glVertex3f(x, y, 0.0f);     // 밑면 점
      glVertex3f(0.0f, 0.0f, height); // 꼭짓점
   }
   glEnd();

   glDisable(GL_LINE_STIPPLE);
   glPopMatrix();

   glFlush();
}



void SetupRC(void) {
   std::cout << "SetupRC" << std::endl;
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glShadeModel(GL_FLAT);
}

void changeSize(GLsizei w, GLsizei h) {
   GLfloat t = 100;
   GLfloat wSizeRatio;
   glViewport(0, 0, w, h);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   wSizeRatio = (GLfloat)w / (GLfloat)h;
   if (w <= h) {
      glOrtho(-t, t, -t / wSizeRatio, t / wSizeRatio, t, -t);
   }
   else {
      glOrtho(-t * wSizeRatio, t * wSizeRatio, -t, t, t, -t);
   }

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("LINE STIPPLE : Cone");

   SetupRC();
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(SpecialKeys);
   glutDisplayFunc(RenderScene);
   glutReshapeFunc(changeSize);
   glutMainLoop();
}