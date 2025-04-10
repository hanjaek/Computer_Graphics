#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void RenderScene(void){

    cout << "RenderScene" << endl;

    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);

    glViewport(0, 0, 640, 480);

    // 좌측하단
    // glOrtho(0, 640, 0, 480, 1, -1);
    // glOrtho(1, -1, 1, -1, 1, -1);

    // 좌측상단
    glOrtho(-320, 320, -240, 240, 1, -1);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glColor3f(1.0f, 0.0f, 0.0f);

    glRectf(0, 240, 320, 0);
    glutSwapBuffers();
}

void SetupRC(void){

    cout << "SetupRC" << endl;
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("study2-2-2");

    SetupRC();
    glutDisplayFunc(RenderScene);

    glutMainLoop();
}