#include <GL/freeglut.h>
#include <iostream>

using namespace std;

void RenderScene(void){
    cout << "RenderScene" << endl;

    // 가장 최근에 그려진 이미지를 지움: Buffer...
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);

    // 왼아래, 오른위 점
    // 좌표계 설정이 없다면, 일반적으로 직교 투영으로 [-1,1] 범위 내에서 작동.
    glRectf(-0.5f, -0.5f, 0.5f, 0.5f);

    // 드로잉 명령을 전달
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
    glutInitWindowPosition(400, 400);
    glutCreateWindow("lecture2_2_1");

    SetupRC();
    glutDisplayFunc(RenderScene);

    glutMainLoop();
}

