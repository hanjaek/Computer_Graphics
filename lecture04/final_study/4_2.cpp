#include <GL/glut.h>
#include <iostream>
#include <cmath>

GLfloat xTran = 0.0f;
GLfloat yTran = 0.0f;
GLfloat xRot = 0.0f;
GLfloat yRot = 0.0f;

void keyboard(unsigned char key, int x, int y){
    if(key == 'a'){
        xTran -= 2.0f;
    }
    else if(key == 'd'){
        xTran += 2.0f;
    }
    else if(key == 's'){
        yTran -= 2.0f;
    }
    else if(key == 'w'){
        yTran += 2.0f;
    }

    glutPostRedisplay();
}

void specialKey(int key, int x, int y){
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

bool bCull = true;
GLfloat GL_PI = 3.14;
bool flag = true;

void RenderScene(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-100,100,-100,100,100,-100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glTranslated(0.0f, 0.0f, -30.0f);
        glRotated(30.0f,1.0f,0.0f,0.0f);
        glRotated(-30.0f, 0.0f, 1.0f, 0.0f);

        glRotatef(xRot, 1.0f, 0.0f, 0.0f);
        glRotatef(yRot, 0.0f, 1.0f, 0.0f);
        glTranslated(xTran, yTran, 0.0f);

    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_LINES);
    glVertex3f(0,0,0);
    glVertex3f(20,0,0);
    glEnd();

    glColor3f(0.0f,1.0f,0.0f);
    glBegin(GL_LINES);
    glVertex3f(0,0,0);
    glVertex3f(0,20,0);
    glEnd();

    glColor3f(0.0f,0.0f,1.0f);
    glBegin(GL_LINES);
    glVertex3f(0,0,0);
    glVertex3f(0,0,20);
    glEnd();

    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x0C0C);
    glutWireCube(10.0f);
    glDisable(GL_LINE_STIPPLE);

    glTranslated(0.0f,20.0f,0.0f);
    glRotated(45, 0.0f,1.0f,0.0f);
    glRotated(45, 0.0f,0.0f,1.0f);
    // glScalef(2.0f,2.0f,2.0f);
    glColor3f(1.0f,0.0f,0.0f);
    glutWireCube(10.0f);
    
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
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKey);
     
    glutMainLoop(); // GLUT의 이벤트 루프 진입 | 윈도우 시스템이 키보드, 마우스, 그리기 이벤트 처리해줌
}