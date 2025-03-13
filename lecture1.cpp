#include <GL/freeglut.h>
#include <iostream>

using namespace std;

void RenderScene(void){
    cout << "RenderScene 실행됨!" << endl;
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();  // 버퍼 교체 (화면 갱신)
}

void SetupRC(void){
    cout << "SetupRC 실행됨!" << endl;
    glClearColor(0.0f, 1.0f, 0.0f, 1.0f);  // 초록색 배경
}

int main(int argc, char** argv){
    cout << "GLUT 초기화 중..." << endl;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);  // GLUT_SINGLE → GLUT_DOUBLE 변경
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("testcode");

    SetupRC();
    glutDisplayFunc(RenderScene);

    cout << "GLUT 메인 루프 진입" << endl;
    glutMainLoop();

    cout << "메인 루프 종료 (여기가 보이면 안 됨)" << endl;
    return 0;
}
