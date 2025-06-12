#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

// key == ‘1’

GLfloat xTran = 0.0f;
GLfloat yTran = 0.0f;
int xRot = 0;
int yRot = 0;

void keyboard(unsigned char key, int x, int y){

    cout << "Keyboard" << "\n";

    if(key=='a'){
        xTran -= 2.0f;
    }
    else if(key =='d'){
        xTran += 2.0f;
    }
    else if(key=='w'){
        yTran += 2.0f;
    }
    else if(key =='s'){
        yTran -= 2.0f;
    }

    glutPostRedisplay();
}

void SpecialKeys(int key, int x, int y){

    cout << "Special Keys" << "\n";

    if(key == GLUT_KEY_UP){
        xRot -= 2.0f;
    }
    if(key == GLUT_KEY_DOWN){
        xRot += 2.0f;
    }
    if(key == GLUT_KEY_LEFT){
        yRot -= 2.0f;
    }
    if(key == GLUT_KEY_RIGHT){
        yRot += 2.0f;
    }

    if(xRot > 360.0f){
        xRot -= 360.0f;
    }
    if(xRot < 0.0f){
        xRot += 360.0f;
    }
    if(yRot > 360.0f){
        yRot -= 360.0f;
    }
    if(yRot < 0.0f){
        yRot += 360.0f;
    }

    glutPostRedisplay();
}

void RenderScene(void)
{
    GLfloat R = (rand()%10) / 100.0f;
    GLfloat G = (rand()%10) / 100.0f;
    GLfloat B = (rand()%10) / 100.0f;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,0.0f,0.0f);

    glPushMatrix();
        glRotatef(xRot, 1.0f, 0.0f, 0.0f);
        glRotatef(yRot, 0.0f, 1.0f, 0.0f);

    glTranslated(xTran, yTran, 0.0f);
    // glTranslated(0.0f, yTran, 0.0f);

    // gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0);

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
                glColor3f(0.3f, 0.7f, 0.3f);
            }
            else{
                glColor3f(0.7f, 0.3f, 0.3f);
            }
            iPivot++;
            glVertex3f(50.0f * cos(angle), 50.0f * sin(angle), 70.0f); 
        }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0.0f, 0.0f, 70.0f);
        iPivot = 1;

        for(float angle = 0.0f; angle <= GL_PI*2.0f; angle+=(GL_PI / 8.0f))
        {
            if((iPivot % 2)==0){
                glColor3f(0.3f, 0.3f, 0.3f);
            }
            else{
                glColor3f(0.7f, 0.7f, 0.7f);
            }
            iPivot++;
            glVertex3f(50.0f * sin(angle), 50.0f * cos(angle), 70.0f); 
        }


    glEnd();
      
    glPopMatrix();

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
        glOrtho(-nRange, nRange, -nRange / aspectRatio, nRange / aspectRatio, -nRange, nRange);
    }
    else{
        glOrtho(-nRange * aspectRatio, nRange * aspectRatio, -nRange, nRange, -nRange, nRange);
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
    glutCreateWindow("Triangle FAN : shape Cone");
    
    SetupRC();
    glutDisplayFunc(RenderScene); // 화면을 그릴 때 RenderScene을 호출
    glutReshapeFunc(ChangeSize);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(SpecialKeys);
     
    glutMainLoop(); // GLUT의 이벤트 루프 진입 | 윈도우 시스템이 키보드, 마우스, 그리기 이벤트 처리해줌
}