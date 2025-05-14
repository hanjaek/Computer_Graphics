#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>

// 점의 크기가 점점 커지는 나선형 출력하기

#define GL_PI 3.1415f
//장면 렌더링
void RenderScene(void)
{
   std::cout << "RenderScene" << std::endl;

   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0f, 1.0f, 1.0f);
   // glRectf(-25.0f, 25.0f, 25.0f, -25.0f);
   glPushMatrix();
      glRotatef(45, 1.0f, 0.0f, 0.0f);
      glRotatef(45, 0.0f, 1.0f, 0.0f);
   
   GLfloat sizes[2] = {1.0f, 20.0f}; // 지원되는 점 크기의 범위를 저장한다.
   GLfloat step = 0.1f; // 지원되는 점 크기의 간격을 지정한다.
   glGetFloatv(GL_POINT_SIZE_RANGE, sizes);
   glGetFloatv(GL_POINT_SIZE_GRANULARITY, &step);


   float z = -50.0f;
   for (float angle = 0.0f; angle <= (6.0f * GL_PI); angle += 0.1f) {
      glBegin(GL_POINTS);
      float x = 50 * cos(angle);
      float y = 50 * sin(angle);
      //std :: cout << x <<','<< y<<',' << z;

      z += 0.5f;
      glVertex3f(x, y, z);
      glColor3f((float)(rand()%10) / 10, (float)(rand()%10) / 10, (float)(rand()%10) / 10);

      // for (float v = 0.0f; v <= 4.0f; v += 0.1f){
      //   glVertex3f(x-2.0f+v, y+2.0f, z);
      //   glVertex3f(x+2.0f, y+2.0f-v, z);
      //   glVertex3f(x-2.0f, y-2.0f+v, z);
      //   glVertex3f(x+2.0f-v, y-2.0f, z);
      // }

      for (float v = 0.0f; v <= 4.0f; v += 0.1f){
         glVertex3f(50.0f*cos(x-2.0f+v), 50.0f*sin(y+2.0f), z);
         glVertex3f(50.0f*cos(x+2.0f), 50.0f*sin(y+2.0f-v), z);
         glVertex3f(50.0f*cos(x-2.0f), 50.0f*sin(y-2.0f+v), z);
         glVertex3f(50.0f*cos(x+2.0f-v), 50.0f*sin(y-2.0f), z);
       }

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