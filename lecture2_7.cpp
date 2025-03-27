#include <GL/freeglut.h>
#include <iostream>

using namespace std;

void RenderScene(void){
    cout << "RenderScene" << endl;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    glRectf(-25.0f, 25.0f, 25.0f, -25.0f);

    glutSwapBuffers(); 
}

void SetupRC(void){
    cout << "SetupRC" << endl;
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

// 윈도우 사이즈를 바꾸면 자동으로 w, h가  생성(현재창의 w, h)
void ChangeSize(GLsizei w, GLsizei h){
    cout << "--> " << "w= " << w << " " << " h= "<< h << endl;
    cout << "ChangeSize" << endl;

    GLint wSize = 100;
    GLfloat aspectRatio = h/w;

    // 창 없어지는 거 방지
    if (h==0){
        h = 1;
    }

    // 창사이즈와 똑같이 생성
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    
    // ****************** Ortho 작성해보기 ***********************
    if(aspectRatio > 1){
        glOrtho(-w, w, -h*aspectRatio, h*aspectRatio, 1, -1);
    }
    else{
        glOrtho(-w*aspectRatio, w*aspectRatio, -h/4, h/4, 1, -1);
    }

    /*
    if (h > w){
    }
    else{
        glOrtho(-w/4, w/4, -h/4, h/4, 1, -1);
    }
    */
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(400, 400);
    glutCreateWindow("lecture2_7");

    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);

    SetupRC();
    glutMainLoop();
}
