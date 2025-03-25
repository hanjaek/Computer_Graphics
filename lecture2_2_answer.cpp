#include <GL/freeglut.h>
#include <iostream>

using namespace std;

void RenderScene(void){
    cout << "RenderScene" << endl;

    int sizeA = 200;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, 640, 480);
    glOrtho(0, 640, 0, 480, 1, -1);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    glRectf(0, 240, 320, 0);
    glutSwapBuffers(); 
}

void SetupRC(void){
    cout << "SetupRC" << endl;
    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(400, 400);
    glutCreateWindow("lecture2");

    SetupRC();
    glutDisplayFunc(RenderScene);

    glutMainLoop();
}

/*

- glMatrixMode(GL_PROJECTION) - 카메라 / 뷰포트 설정 (카메라 좌표계 설정)

<PROJECTION MODE>
1. glOrtho() - 원근감 X
2. gluPerspectiver() - 원근감 O ex)기찻길길

---------------------------------------------------------------------------------

- glMatrixMode(GL_MODELVIEW) - 객체 변환 (이동, 회전, 크기변경) (객체 좌표계 설정)

*/
