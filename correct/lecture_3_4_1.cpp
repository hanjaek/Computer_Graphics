#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

#define GL_PI 3.1415f
//장면 렌더링
void RenderScene(void)
{
   std::cout << "RenderScene" << std::endl;

   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0f, 1.0f, 1.0f);
   //glRectf(-25.0f, 25.0f, 25.0f, -25.0f);

   GLfloat sizes[2];
   GLfloat step;

   glGetFloatv(GL_LINE_WIDTH_RANGE,sizes);
   glGetFloatv(GL_LINE_WIDTH_GRANULARITY, &step);

   GLfloat space = 50.0f;
   GLfloat x = 50.0f;
   GLfloat y = 50.0f;
   GLfloat size = sizes[0];
   // cout << sizes[0] << " " << sizes[1] << " " << step << endl;
   // 0.0078125, 2046.99, step = 0.0078125

   for(int i=0; i < 9; i++){

      glLineWidth(size);
      size += step*300;

      glBegin(GL_LINES);

      glColor3f((float)(rand()%10) / 10, (float)(rand()%10) / 10, (float)(rand()%10) / 10);
      glVertex3f(x, 50.0f, 0);
      glColor3f((float)(rand()%10) / 10, (float)(rand()%10) / 10, (float)(rand()%10) / 10);
      glVertex3f(x, 450.0f, 0);
      glColor3f((float)(rand()%10) / 10, (float)(rand()%10) / 10, (float)(rand()%10) / 10);
      glVertex3f(50.0f, y, 0);
      glColor3f((float)(rand()%10) / 10, (float)(rand()%10) / 10, (float)(rand()%10) / 10);
      glVertex3f(450.0f, y, 0);

      x += space;
      y += space;

      glEnd();

   }
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

   /** 
   aspectRatio = (GLfloat)w / (GLfloat)h;
   if (w <= h)
      glOrtho(-wSize, wSize, -wSize / aspectRatio, wSize / aspectRatio, 100, -100);
   else
      glOrtho(-wSize * aspectRatio, wSize * aspectRatio, -wSize, wSize, 100, -100);
   **/
   glOrtho(0, 500, 0, 500, 1, -1);

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