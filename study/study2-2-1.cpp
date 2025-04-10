#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void RenderScene(void){

    cout << "RenderScene" << endl;

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);

    glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
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
    glutCreateWindow("study2-2-1");

    SetupRC();
    glutDisplayFunc(RenderScene);

    glutMainLoop();
}