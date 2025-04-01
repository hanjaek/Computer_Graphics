#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

void RenderScene(void) {
    std::cout << "RenderScene" << std::endl;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(2.0f);

    glLoadIdentity();
    glBegin(GL_POINTS); // 기본 모델로 점을 선택한다.
    for (float i = 0.0f; i <= 360.0f; i += 1.0f) {
        // float x = 50.0f * i;
        // float y = 50.0f * i;
        // float z = 50.0f * i;
        // glVertex3f(x, y, z); // 점을 지정한다.
        glVertex3f(cos(i), sin(i), i);
    }
    glEnd();

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
        glOrtho(-wSize, wSize, -wSize / aspectRatio, wSize / aspectRatio, -100, 100);
    }
    else {
        glOrtho(-wSize * aspectRatio, wSize * aspectRatio, -wSize, wSize, -100, 100);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(400, 400);
    glutCreateWindow("Draw circle");

    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);

    SetupRC();
    glutMainLoop();
}
