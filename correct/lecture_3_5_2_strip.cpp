#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

#define GL_PI 3.1415f
//장면 렌더링
void RenderScene(void)
{
   std::cout << "RenderScene" << std::endl;

   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0f, 1.0f, 1.0f);
   //glRectf(-25.0f, 25.0f, 25.0f, -25.0f);
   glPushMatrix();
      glRotatef(45, 1.0f, 0.0f, 0.0f);
      glRotatef(45, 0.0f, 1.0f, 0.0f);
   glPointSize(3);


   GLfloat line = 100.0f;
   GLfloat arrow = 5.0f;

   glBegin(GL_LINE_STRIP); 
   // x축 점 2개
   glColor3f(1.0f, 0.0f, 0.0f);
   glVertex3f(0.0f, 0.0f, 0.0f);
   glVertex3f(line, 0.0f, 0.0f);

   // x축 화살표 점 3개
   glVertex3f(90.0f, 0.0f, -arrow);
   glVertex3f(line, 0.0f, 0.0f);
   glVertex3f(90.0f, 0.0f, arrow);
   glEnd();

   glBegin(GL_LINE_STRIP);
   // y축 점 2개
   glColor3f(0.0f, 1.0f, 0.0f);
   glVertex3f(0.0f, 0.0f, 0.0f);
   glVertex3f(0.0f, line, 0.0f);

   // y축 화살표 점 3개
   glVertex3f(-arrow, 90.0f, 0.0f);
   glVertex3f(0.0f, line, 0.0f);
   glVertex3f(arrow, 90.0f, 0.0f);
   glEnd();

   glBegin(GL_LINE_STRIP);
   // z축 점 2개
   glColor3f(0.0f, 0.0f, 1.0f);
   glVertex3f(0.0f, 0.0f, 0.0f);
   glVertex3f(0.0f, 0.0f, line);

   // z축화살표 점 3개
   glVertex3f(-arrow, 0.0f, 90.0f);
   glVertex3f(0.0f, 0.0f, line);
   glVertex3f(arrow, 0.0f, 90.0f);
   glEnd();

   glPopMatrix();
   //glFlush();
   glutSwapBuffers();
}

void SetupRC(void)
{
   std::cout << "SetupRC" << std::endl;
   glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

}

void ChangeSize(GLsizei w, GLsizei h)
{
   std::cout << "w = " << w << " " << "h = " << h << std::endl;
   std::cout << "ChangeSize" << std::endl;

   GLint wSize = 100;
   GLfloat aspectRatio;

   if (h == 0)
      h = 1;

   glViewport(0, 0, w, h);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   aspectRatio = (GLfloat)w / (GLfloat)h;
   if (w <= h)
      glOrtho(-wSize, wSize, -wSize / aspectRatio, wSize / aspectRatio, 100, -100);
   else
      glOrtho(-wSize * aspectRatio, wSize * aspectRatio, -wSize, wSize, 100, -100);


   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}
int main(int argc, char** argv)
{
   glutInit(&argc, argv); //glut 초기화
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   //glutInitWindowSize(640, 480);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(400, 400);
   glutCreateWindow("simple");

   glutDisplayFunc(RenderScene);
   glutReshapeFunc(ChangeSize);

   SetupRC();
   glutMainLoop();
}