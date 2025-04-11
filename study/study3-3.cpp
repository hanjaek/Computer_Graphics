#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

#define GL_PI 3.141592f

void RenderScene(void) {
    std::cout << "RenderScene" << std::endl;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    glLoadIdentity();
    glPushMatrix();
      glRotatef(45, 1.0f, 0.0f, 0.0f);
      glRotatef(45, 0.0f, 1.0f, 0.0f);


    float z = -50.0f;

    for(float angle = 0.0f; angle <= GL_PI * 2.0f * 3.0f; angle += 0.1f){
        float x = 50.0f * cos(angle);
        float y = 50.0f * sin(angle);
        
        glColor3f((float)(rand()%10) / 10, (float)(rand()%10) / 10, (float)(rand()%10) / 10);

        glBegin(GL_POINTS);
        for (float dot = -2.0f; dot <= 2.0f; dot += 0.1f) {
            glVertex3f(x + dot, y + 2.0f, z);     // 상단: 왼쪽 → 오른쪽
            glVertex3f(x + 2.0f, y - dot, z);     // 오른쪽: 위 → 아래
            glVertex3f(x - 2.0f, y + dot, z);     // 왼쪽: 아래 → 위
            glVertex3f(x - dot, y - 2.0f, z);     // 하단: 오른쪽 → 왼쪽
        }
        z += 0.5f;

        glEnd();

    }

    glutSwapBuffers(); 
}

void SetupRC(void){

    cout << "SetupRC" << endl;
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void ChangeSize(GLsizei w, GLsizei h){

    cout << "w = " << w << " " << "h = " << h << endl;
    cout << "ChangeSize" << endl;

    GLint wSize = 100;
    GLfloat aspectRatio;

    if(h==0){
        h=1;
    }
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    aspectRatio = (GLfloat)w / (GLfloat)h;
    if (w<=h){
        glOrtho(-wSize, wSize, -wSize / aspectRatio, wSize / aspectRatio, 100, -100);
    }
    else{
        glOrtho(-wSize * aspectRatio, wSize * aspectRatio, -wSize, wSize, 100, -100);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


}

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("study3-3");

    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);

    SetupRC();
    glutMainLoop();
}