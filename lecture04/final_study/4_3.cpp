#include <GL/glut.h>
#include <iostream>
#include <cmath>

int flag = 0;

void RenderScene(void)
{

    glOrtho(-100,100,-100,100,100,-100);


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0f,0.0f,0.0f);

    if(flag == 0){
        glClearColor(1.0f,0.0f,0.0f,1.0f);
        flag++;
    }
    else if(flag == 1){
        glClearColor(0.0f,1.0f,0.0f,1.0f);
        flag++;
    }
    else{
        glClearColor(0.0f,0.0f,1.0f,1.0f);
        flag = 0;
    }

    glutSwapBuffers();
}

void TimerFunc(int value){
    glutPostRedisplay();
    glutTimerFunc(1000, TimerFunc, 1);
}

void SetupRC(void)
{
    glClearColor(1.0f,0.0f,0.0f,1.0f);
    glShadeModel(GL_FLAT); 
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // 디스플레이 모드 설정 | Single 버퍼, RGBA 색상 모드 사용
    glutInitWindowSize(500, 500);
    
    glutInitWindowPosition(100, 100);
    glutCreateWindow("simple");
    
    SetupRC();
    glutDisplayFunc(RenderScene); // 화면을 그릴 때 RenderScene을 호출
    glutTimerFunc(1000, TimerFunc, 1);
     
    glutMainLoop(); // GLUT의 이벤트 루프 진입 | 윈도우 시스템이 키보드, 마우스, 그리기 이벤트 처리해줌
}