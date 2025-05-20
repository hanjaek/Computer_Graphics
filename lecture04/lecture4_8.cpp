#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

void RenderScene(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,0.0f,0.0f);

    glPushMatrix();
        glRotatef(180, 1.0f, 0.0f, 0.0f);
        //glRotatef(180, 0.0f, 1.0f, 0.0f);

    gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0);

    float GL_PI = 3.14f;
    GLfloat x, y;
    int iPivot = 1;
    bool bCull = true;

    if(bCull){
        glEnable(GL_CULL_FACE);
    }
    else{
        glDisable(GL_CULL_FACE);
    }

    glBegin(GL_TRIANGLE_FAN);

        glVertex3f(0.0f, 0.0f, 0.0f);

        // 10진수는 많은 자리까지 계산 못하는 경우가 있음 즉 angle을 8.0으로 나누었을 때는 잘 채워지지만
        // 16.0으로 나누었을 때 조각이 비는 경우가 생김. 즉, 항상 오차가 존재함. -> 오차에의해 비교관계에 성립할 수도 안할 수도 있는 것임.

        for(float angle = 0.0f; angle < GL_PI*2.0f; angle+=(GL_PI / 8.0f))
        {
            if((iPivot % 2)==0){
                glColor3f(0.0f, 1.0f, 0.0f);
            }
            else{
                glColor3f(1.0f, 0.0f, 0.0f);
            }
            iPivot++;
            glVertex3f(50.0f * sin(angle), 50.0f * cos(angle), 0.0f); 
        }


    glEnd();
      
    // glPopMatrix();

    glutSwapBuffers();
}

void SetupRC(void)
{
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glShadeModel(GL_FLAT); // glShadeModel(GL_FLAT)은 마지막색상을 입힘. GL_SMOOTH는 버텍스마다 색상정보를 가져서 부드럽게 이어짐
}

void ChangeSize(GLsizei w, GLsizei h){
    cout << "ChangeSize" << "\n";

    GLdouble nRange = 100.0f;
    GLdouble aspectRatio;

    if(h==0) h=1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    aspectRatio = (GLfloat)w / (GLfloat)h;
    if( w <= h){
        glOrtho(-nRange, nRange, -nRange / aspectRatio, nRange / aspectRatio, nRange, -nRange);
    }
    else{
        glOrtho(-nRange * aspectRatio, nRange * aspectRatio, -nRange, nRange, nRange, -nRange);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // 디스플레이 모드 설정 | Single 버퍼, RGBA 색상 모드 사용
    glutInitWindowSize(500, 500);
    
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Triangle FAN -> RG Circle -> GL_CULL_FACE(후면제거)");
    
    SetupRC();
    glutDisplayFunc(RenderScene); // 화면을 그릴 때 RenderScene을 호출
    glutReshapeFunc(ChangeSize);
     
    glutMainLoop(); // GLUT의 이벤트 루프 진입 | 윈도우 시스템이 키보드, 마우스, 그리기 이벤트 처리해줌
}