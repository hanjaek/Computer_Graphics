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

    // glPushMatrix();
    //     glRotatef(45, 1.0f, 0.0f, 0.0f);
    //     glRotatef(45, 0.0f, 1.0f, 0.0f);

    GLfloat len = 20.0f;
    GLint factor = 4;
    GLushort pattern = 0x5555;

    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(len, len, 0.0f);

    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(-len, len, 0.0f);

    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.0f,len,0.0f);

    glVertex3f(-len, len, 0.0f);
    glVertex3f(-len, 2*len, 0.0f);

    glVertex3f(len, len, 0.0f);
    glVertex3f(len, 2*len, 0.0f);

    glVertex3f(-len, 2*len, 0.0f);
    glVertex3f(0.0f,len,0.0f);

    glVertex3f(len, 2*len, 0.0f);
    glVertex3f(0.0f,len,0.0f);

    glVertex3f(0.0f,3*len,0.0f);
    glVertex3f(len, 2*len, 0.0f);

    glVertex3f(0.0f,3*len,0.0f);
    glVertex3f(-len, 2*len, 0.0f);

    glEnd();

    glEnable(GL_LINE_STIPPLE);
    glLineStipple(factor, pattern);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 2*len, 0.0f);
    glVertex3f(-len, len, 0.0f);

    glVertex3f(0.0f, 2*len, 0.0f);
    glVertex3f(len, len, 0.0f);

    glVertex3f(0.0f, 2*len, 0.0f);
    glVertex3f(0.0f, 3*len, 0.0f);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
    
    glPopMatrix();

    glutSwapBuffers();
}

void SetupRC(void)
{
    glClearColor(0.0f,0.0f,0.0f,1.0f);
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