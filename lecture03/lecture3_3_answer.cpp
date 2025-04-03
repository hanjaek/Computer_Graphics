#include <GL/glut.h>
#include <iostream>
#include <math.h>

// 장면 렌더링
void RenderScene(void)
{
    std::cout << "RenderScene" << std::endl;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-10, 10, -10, 10, 100, -100); // left, right, bottom, top, near, far

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);

    // 점의 크기
    glPointSize(1.0f);
    
    float GL_PI = 3.14159265359f;

    glBegin(GL_POINTS);
        for(float angle = 0.0f; angle <= GL_PI*2.0f; angle+=0.005f)
        {
            glVertex3f(cos(angle), sin(angle), 0); // 라디아
        }
    glEnd();
    
    // 드로잉 명령을 전달한다. 명령을 강제로 실행하여 즉시 렌더링, GLUT_SINGLE (단일 버퍼)
    glutSwapBuffers(); 
}

// 렌더링 관련 초기 설정
void SetupRC(void)
{
    std::cout << "SetupRC" << std::endl;
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // R G B A
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // 디스플레이 모드 설정 | Single 버퍼, RGBA 색상 모드 사용
    glutInitWindowSize(500, 500);
    
    glutInitWindowPosition(100, 100);
    glutCreateWindow("simple");
    
    SetupRC();
    glutDisplayFunc(RenderScene); // 화면을 그릴 때 RenderScene을 호출
     
    glutMainLoop(); // GLUT의 이벤트 루프 진입 | 윈도우 시스템이 키보드, 마우스, 그리기 이벤트 처리해줌
}
