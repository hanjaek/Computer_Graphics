#include <GL/freeglut.h>
#include <iostream>

using namespace std;

void RenderScene(void){
    cout << "RenderScene 실행" << endl;

    // 가장 최근에 그려진 이미지를 지움: Buffer...
    glClear(GL_COLOR_BUFFER_BIT);

    // 버퍼 교체 (화면 갱신)
    glutSwapBuffers(); 
}

void SetupRC(void){
    cout << "SetupRC 실행" << endl;

    // 화면을 어떤 색으로 지울지 결정 (실제로 화면을 지우기 위해서 glClear호출)
    glClearColor(0.0f, 1.0f, 0.0f, 1.0f);  
}

int main(int argc, char** argv){
    cout << "GLUT 초기화 중..." << endl;
    glutInit(&argc, argv);

    // 더블버퍼와 RGB체계 사용
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 
    
    // width, height 픽셀
    glutInitWindowSize(640, 480);

    // 좌측 상단 끝이 (0,0)
    glutInitWindowPosition(100, 100);
    glutCreateWindow("lecture1 - freeglut test code");

    // 렌더링이 이루어지기 전에 필요한 OpenGL 초기화화
    SetupRC();

    // func 함수를 호출하는 콜백함수
    // 창의 이동/크기 변경 될 때마다 호출
    glutDisplayFunc(RenderScene);

    cout << "GLUT 메인 루프 진입" << endl;

    // GLUT 프레임웍 실행, 프로그램이 종료될 때까지 운영체제에 관련된 메시지, 키, 입력 등을 처리
    glutMainLoop();

    cout << "메인 루프 종료 (여기가 보이면 안 됨)" << endl;
    return 0;
}
