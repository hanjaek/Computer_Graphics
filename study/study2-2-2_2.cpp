#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void RenderScene(void){

    cout << "RenderScene" << endl;

    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);

    glViewport(0, 0, 500, 500);

    glOrtho(0, 500, 0, 500, 1, -1);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glColor3f(1.0f, 0.0f, 0.0f);

    glRectf(250, 375, 375, 250);
    glutSwapBuffers();
}

void SetupRC(void){

    cout << "SetupRC" << endl;
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("study2-2-2_2");

    SetupRC();
    glutDisplayFunc(RenderScene);

    glutMainLoop();
}