#include <GL/glut.h>
#include <iostream>
#include <cmath>

void RenderScene(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-100,100,-100,100,100,-100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // glPushMatrix();
    //     glRotatef(45, 1.0f, 0.0f, 0.0f);
    //     glRotatef(45, 0.0f, 1.0f, 0.0f);
    glColor3f(1.0f,0.0f,0.0f);
    bool bCull = true;
    GLfloat GL_PI = 3.14;
    bool flag = true;

    if(bCull){
        glEnable(GL_CULL_FACE);
    }
    else{
        glDisable(GL_CULL_FACE);
    }

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f,0.0f,0.0f);;
    glColor3f(1.0f, 0.0f,0.0f);

    for(GLfloat angle = 0.0f; angle < 2.0f*(GL_PI); angle += (GL_PI / 8.0f)){
        GLfloat x = 50.0f * cos(angle);
        GLfloat y = 50.0f * sin(angle);
        if(flag){
            glColor3f(0.0f, 1.0f,0.0f);
            flag = false;
        }
        else{
            glColor3f(1.0f, 0.0f,0.0f);
            flag = true;
        }
        glVertex3f(x, y, angle);
    }
    glEnd();
    
    glPopMatrix();

    glutSwapBuffers();
}

void SetupRC(void)
{
    glClearColor(0.0f,0.0f,0.0f,1.0f);
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
     
    glutMainLoop(); // GLUT의 이벤트 루프 진입 | 윈도우 시스템이 키보드, 마우스, 그리기 이벤트 처리해줌
}