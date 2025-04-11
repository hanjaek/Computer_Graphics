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

    GLfloat sizes[2];
    GLfloat step;

    glGetFloatv(GL_POINT_SIZE_RANGE, sizes);
    glGetFloatv(GL_POINT_SIZE_GRANULARITY, &step);


    // cout << sizes[0] << " " << sizes[1] << " " << step << endl;;
    /** 
    최소 사이즈: 1
    최대 사이즈: 20
    step: 0.125
    **/


    float z = -50.0f;

    for(float angle = 0.0f; angle <= GL_PI * 2.0f * 3.0f; angle += 0.1f){
        float x = 50.0f * cos(angle);
        float y = 50.0f * sin(angle);

        glPointSize(sizes[0]);
        sizes[0] += step;
        
        glBegin(GL_POINTS);

        glVertex3f(x, y, z);
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
    glutCreateWindow("study3-2");

    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);

    SetupRC();
    glutMainLoop();
}