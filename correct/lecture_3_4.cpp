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
   glPointSize(10);
   // pointSize 영향 x

   glLineWidth(10);
   GLfloat sizes[2];
   GLfloat step;
   glBegin(GL_LINE_STRIP);
   float z = -50.0f;

   for (float angle = 0.0f; angle <= (6.0f * GL_PI); angle += 0.1f) {
      float x = 50 * cos(angle);
      float y = 50 * sin(angle);
      //std :: cout << x <<','<< y<<',' << z;
      z += 0.5f;
      glVertex3f(x, y, z);
   }

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
   glutCreateWindow("Line strip");

   glutDisplayFunc(RenderScene);
   glutReshapeFunc(ChangeSize);

   SetupRC();
   glutMainLoop();
}