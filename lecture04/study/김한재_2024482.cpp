#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

GLfloat GL_PI = 3.141592f;
GLfloat action = 0.0f;

void keyboard(unsigned char key, int x, int y){

    cout << "Keyboard" << "\n";

    if(key=='1'){
        action = GL_PI / 4.0f;
    }
    else if(key =='2'){
        action = (GL_PI / 4.0f)*2;
    }
    else if(key=='3'){
        action = (GL_PI / 4.0f)*3;
    }
    else if(key =='4'){
        action = (GL_PI / 4.0f)*4;
    }
    else if(key =='5'){
        action = (GL_PI / 4.0f)*5;
    }
    else if(key=='6'){
        action = (GL_PI / 4.0f)*6;
    }
    else if(key =='7'){
        action = (GL_PI / 4.0f)*7;
    }
    else if(key =='8'){
        action = (GL_PI / 4.0f)*8;
    }
    glutPostRedisplay();
}

void RenderScene(void)
{
    cout << "render" << endl;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 1.0f, 0.0f);
    bool flag = true;

    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0.0f,0.0f,0.0f);
        for(float angle = 0.0f; angle <= action; angle+=(GL_PI / 4.0f))
        {
            if(flag){
                glColor3f(1.0f, 0.0f, 0.0f);
                flag = false;
            }
            else{
                glColor3f(0.0f, 1.0f, 0.0f);
                flag = true;
            }
            glVertex3f(50.0f * cos(angle), 50.0f * sin(angle), 0.0f); 
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
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 
    glutInitWindowSize(500, 500);
    
    glutInitWindowPosition(100, 100);
    glutCreateWindow("김한재_2024482_MAKE_TRIANGLE(1~8)");
    
    SetupRC();
    glutDisplayFunc(RenderScene); 
    glutReshapeFunc(ChangeSize);
    glutKeyboardFunc(keyboard);
     
    glutMainLoop();
}