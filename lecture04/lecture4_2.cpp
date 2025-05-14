#include <GL/glut.h>
#include <iostream>

void RenderScene(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-100,100,-100,100,100,-100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,0.0f,0.0f);

    // glPushMatrix();
    //     glRotatef(45, 1.0f, 0.0f, 0.0f);
    //     glRotatef(45, 0.0f, 1.0f, 0.0f);

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);    
        glVertex2f(0.0f, 0.0f);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(50.0f, 0.0f);
        
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(50.0f, 50.0f);
    glEnd();
        
    // glPopMatrix();

    glutSwapBuffers();
}

void SetupRC(void)
{
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glShadeModel(GL_SMOOTH); // glShadeModel(GL_FLAT)은 마지막색상을 입힘. GL_SMOOTH는 버텍스마다 색상정보를 가져서 부드럽게 이어짐
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // 디스플레이 모드 설정 | Single 버퍼, RGBA 색상 모드 사용
    glutInitWindowSize(500, 500);
    
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rainbow Triangle");
    
    SetupRC();
    glutDisplayFunc(RenderScene); // 화면을 그릴 때 RenderScene을 호출
     
    glutMainLoop(); // GLUT의 이벤트 루프 진입 | 윈도우 시스템이 키보드, 마우스, 그리기 이벤트 처리해줌
}