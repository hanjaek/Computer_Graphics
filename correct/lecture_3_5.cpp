#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

#define GL_PI 3.1415f
//장면 렌더링
void RenderScene(void)
{
    GLfloat y;
    GLint factor = 1;
    GLushort pattern = 0x00ff; // 0x5555 : 0101 0101 0101 0101 / 00ff : 0000 0000 1111 1111
                     // 그려질 때는 반대로 : ff00으로 그려짐 즉 1111 1111 0000 0000 < 그려지고 안그려지고,

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();

    glEnable(GL_LINE_STIPPLE);
    for(y = -90.0f; y <= 90.0f; y += 20.0f){
        glLineStipple(factor, pattern);

        glBegin(GL_LINES);
            // glVertex2f(-80.0f, y);
            // glVertex2f(80.0f, y);
            glVertex2f(y, -80.0f);
            glVertex2f(y, 80.0f);
        glEnd();

        factor++; // 간격과 길이가 ++
    }

    glPopMatrix();

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
   glOrtho(-100, 100, -100, 100, 1, -1);

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