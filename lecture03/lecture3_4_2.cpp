#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

void RenderScene(void)
{
    std::cout << "RenderScene" << std::endl;

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f);

    glPushMatrix();
        glRotatef(45, 1.0f, 0.0f, 0.0f);
        glRotatef(45, 0.0f, 1.0f, 0.0f);

    
    float GL_PI = 3.14159265359f;
    float z = 0.0f;

    glBegin(GL_POINTS);
        glVertex3f(0,0,0);
        for(float angle = 0.0f; angle <= GL_PI*6.0f; angle+=0.1f)
        {
            z += 0.1f * GL_PI;
            glVertex3f(50 * cos(angle), 50 * sin(angle), z); // 라디아
        }
    glEnd();

    glPopMatrix();
    
    glutSwapBuffers(); 
}

void SetupRC(void) {
    std::cout << "SetupRC" << std::endl;
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}


void ChangeSize(GLsizei w, GLsizei h) {
    GLint wSize = 10;
    GLfloat aspectRatio;

    if (h == 0) h = 1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    aspectRatio = (GLfloat)w / (GLfloat)h;
    if (w <= h) {
        glOrtho(-wSize, wSize, -wSize / aspectRatio, wSize / aspectRatio, 100, -100);
    }
    else {
        glOrtho(-wSize * aspectRatio, wSize * aspectRatio, -wSize, wSize, 100, -100);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(400, 400);
    glutCreateWindow("Draw Spring");

    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);

    SetupRC();
    glutMainLoop();
}
