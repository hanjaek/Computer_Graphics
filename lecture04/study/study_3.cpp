#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

#define GL_PI 3.1415f 
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

void RenderScene() {
   float x, y, z = 75.0f;
   float centerX = 0.0f, centerY = 0.0f, centerZ = 0.0f;
   float radius = 50.0f;
   bool flag = false;
   bool bCull = true;

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glEnable(GL_DEPTH_TEST);

   if (bCull) {
      glEnable(GL_CULL_FACE);
   }
   else {
      glDisable(GL_CULL_FACE);
   }

   glPushMatrix();
   glTranslatef(xTran, yTran, 0.0f);
   glRotatef(xRot, 1.0f, 0.0f, 0.0f);
   glRotatef(yRot, 0.0f, 1.0f, 0.0f);

   float hs = 100.0f / 2.0f;

   // 앞면 (z = +hs)
   glBegin(GL_TRIANGLE_FAN);
   glColor3f(1, 0, 0);
   glVertex3f(0, 0, hs);
   glVertex3f(-hs, -hs, hs);
   glVertex3f(hs, -hs, hs);
   glVertex3f(hs, hs, hs);
   glVertex3f(-hs, hs, hs);
   glVertex3f(-hs, -hs, hs);
   glEnd();

   // 뒷면 (z = -hs)
   glBegin(GL_TRIANGLE_FAN);
   glColor3f(0, 1, 0);
   glVertex3f(0, 0, -hs);
   glVertex3f(-hs, -hs, -hs);
   glVertex3f(-hs, hs, -hs);
   glVertex3f(hs, hs, -hs);
   glVertex3f(hs, -hs, -hs);
   glVertex3f(-hs, -hs, -hs);
   glEnd();

   // 왼쪽 면 (x = -hs)
   glBegin(GL_TRIANGLE_FAN);
   glColor3f(0, 0, 1);
   glVertex3f(-hs, 0, 0);
   glVertex3f(-hs, -hs, -hs);
   glVertex3f(-hs, -hs, hs);
   glVertex3f(-hs, hs, hs);
   glVertex3f(-hs, hs, -hs);
   glVertex3f(-hs, -hs, -hs);
   glEnd();

   // 오른쪽 면 (x = +hs)
   glBegin(GL_TRIANGLE_FAN);
   glColor3f(1, 1, 0);
   glVertex3f(hs, 0, 0);
   glVertex3f(hs, -hs, hs);
   glVertex3f(hs, -hs, -hs);
   glVertex3f(hs, hs, -hs);
   glVertex3f(hs, hs, hs);
   glVertex3f(hs, -hs, hs);
   glEnd();

   // 윗면 (y = +hs)
   glBegin(GL_TRIANGLE_FAN);
   glColor3f(0, 1, 1);
   glVertex3f(0, hs, 0);
   glVertex3f(-hs, hs, hs);
   glVertex3f(hs, hs, hs);
   glVertex3f(hs, hs, -hs);
   glVertex3f(-hs, hs, -hs);
   glVertex3f(-hs, hs, hs);
   glEnd();

   // 아랫면 (y = -hs)
   glBegin(GL_TRIANGLE_FAN);
   glColor3f(1, 0, 1);
   glVertex3f(0, -hs, 0);
   glVertex3f(-hs, -hs, -hs);
   glVertex3f(hs, -hs, -hs);
   glVertex3f(hs, -hs, hs);
   glVertex3f(-hs, -hs, hs);
   glVertex3f(-hs, -hs, -hs);
   glEnd();
   glPopMatrix();

   //glFlush();
   glutSwapBuffers();
}



void SetupRC(void) {
   std::cout << "SetupRC" << std::endl;
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glShadeModel(GL_FLAT); // 한번만 실행되면 되는 거라서, SetUpRC함수에 넣음.
   //glShadeModel(GL_SMOOTH);
}

void changeSize(GLsizei w, GLsizei h) {
   GLfloat t = 100;
   GLfloat wSizeRatio;
   glViewport(0, 0, w, h); // 도화지는 카메라의 투영과 상관없으니, glMatrixMode()함수 안에 들어가지 x

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   wSizeRatio = (GLfloat)w / (GLfloat)h;
   if (w <= h) { // 세로로 창이 늘어남 -> 투영을 세로로 확장
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
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("Color Cube");

   SetupRC();
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(SpecialKeys);
   glutDisplayFunc(RenderScene);
   glutReshapeFunc(changeSize);
   glutMainLoop();
}