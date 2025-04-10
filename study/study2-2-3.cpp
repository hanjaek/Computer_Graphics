#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void RenderScene(void){

    cout << "RenderScene" << endl;

    glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(1.0f, 0.0f, 0.0f);

    glRectf(-25.0f, 25.0f, 25.0f, -25.0f);

    glutSwapBuffers();
}

void SetupRC(void){

    cout << "SetupRC" << endl;
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

void ChangeSize(GLsizei w, GLsizei h){

    cout << "w = " << w << " " << "h = " << h << endl;
    cout << "ChangeSize" << endl;

    GLint wSize = 100;
    GLfloat aspectRatio;

    if(h==0){
        h=1;
    }
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    aspectRatio = (GLfloat)w / (GLfloat)h;
    if (w<=h){
        glOrtho(-wSize, wSize, -wSize / aspectRatio, wSize / aspectRatio, 1, -1);
    }
    else{
        glOrtho(-wSize * aspectRatio, wSize * aspectRatio, -wSize, wSize, 1, -1);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


}

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("study2-2-3");

    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);

    SetupRC();
    glutMainLoop();
}