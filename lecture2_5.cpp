#include <GL/freeglut.h>
#include <iostream>

using namespace std;

void RenderScene(void){
    cout << "RenderScene" << endl;

    int sizeA = 200;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, 250, 500);

    // 클리핑 느낌으로 생각하면 됨
    glOrtho(-1, 1, -1, 1, 1, -1);

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);

    // x1(좌측하단), y1(좌측상단), x2(우측상단) ,y2(우측하단)
    // (x1,y1) = 좌측상단 좌표 / (x2,y2) = 우측하단좌표
    glRectf(-0.25f, 0.25f, 0.25f, -0.25f);
    glutSwapBuffers(); 
}

void SetupRC(void){
    cout << "SetupRC" << endl;
    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(400, 400);
    glutCreateWindow("lecture2_4");

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
