#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

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
int flag = 0;

void RenderScene(void)
{
    // GLint factor = 4;
    // GLushort pattern = 0x5555;
    std::cout << "RenderScene" << std::endl;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(flag == 0){
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        flag++;
    }
    else if(flag == 1){
        glClearColor(0.0f, 1.0f, 0.0f,1.0f);
        flag++;
    }
    else{
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
        flag = 0;
    }
    
    glutSwapBuffers();
}

void TimerFunction(int value){
    //glutDisplayFunc();
    glutPostRedisplay();

    //1초마다 다시 호출
    glutTimerFunc(1000, TimerFunction, 1);
}

void SetupRC(void)
{
    glClearColor(1.0f,0.0f,0.0f,1.0f);
    // glShadeModel(GL_FLAT); 
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
    if(w <= h){
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
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // 디스플레이 모드 설정 | Single 버퍼, RGBA 색상 모드 사용
    glutInitWindowSize(500, 500);
    
    glutInitWindowPosition(100, 100);
    glutCreateWindow("glutTimer : RGB");
    
    SetupRC();
    glutDisplayFunc(RenderScene); // 화면을 그릴 때 RenderScene을 호출
    glutReshapeFunc(ChangeSize);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(SpecialKeys);
    glutTimerFunc(1000, TimerFunction, 1); // 처음 타이머 호출
     
    glutMainLoop(); // GLUT의 이벤트 루프 진입 | 윈도우 시스템이 키보드, 마우스, 그리기 이벤트 처리해줌
}