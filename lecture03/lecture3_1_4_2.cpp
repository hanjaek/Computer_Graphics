#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

// 점의 크기가 점점 커지는 나선형 출력하기 - z축으로 나열하기 
// z축으로 나열

void RenderScene(void)
{
   cout << "RenderScene" << endl;

   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0f, 1.0f, 1.0f);
   // glRectf(-25.0f, 25.0f, 25.0f, -25.0f);
   glPushMatrix();
      glRotatef(45, 1.0f, 0.0f, 0.0f);
      glRotatef(45, 0.0f, 1.0f, 0.0f);
   
   GLfloat sizes[2]; 
   GLfloat step;
   glGetFloatv(GL_POINT_SIZE_RANGE, sizes);
   glGetFloatv(GL_POINT_SIZE_GRANULARITY, &step);

   cout << sizes[0] << "-" << sizes[1] << "-" << step << "\n";
   // min = 1, max = 20, step = 0.125

   float z = -50.0f;
   for (float size = sizes[0]; size <= sizes[1]; size += step) {
      glPointSize(sizes[0]+=step);
      glBegin(GL_POINTS);
      z += 1.0f;
      glVertex3f(1, 1, z);
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