#include <GL/freeglut.h>
#include <iostream>

using namespace std;

void RenderScene(void){
    cout << "RenderScene" << endl;

    // 가장 최근에 그려진 이미지를 지움: Buffer...
    glClear(GL_COLOR_BUFFER_BIT);

    // 드로잉 색상 지정
    glColor3f(1.0f, 0.0f, 0.0f);

    /**
    - 사각형 그려주는 함수 (왼 위x, 왼 위y, 오른 아래x, 오른 아래 y)

    - 왼아래, 오른위 점

    - 좌표계 설정이 없다면, 일반적으로 직교 투영으로 [-1,1] 범위 내에서 작동 
      -> 변경하려면 glOrtho() 함수 사용
    **/
    glRectf(-0.25f, -0.25f, 0.25f, 0.25f);
    // 정사각형 값이지만 윈도우 가로 세로의 크기가 다르면 직사각형

    // 드로잉 명령을 전달
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
    glViewport(0, 0, 500, 500);
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
