// atom.c - A simple OpenGL animation of a rotating atom
#include <GL/glut.h>
#include <math.h>

void RenderScene(void)
{
    //핵 주위의 공전 각도 설정
    static GLfloat rotate = 0.0f;
    //창의 내용을 지움
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //모델뷰 행렬 초기화
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1.0f,0.0f,0.0f);
    glutSolidSphere(20, 30, 30);

    glColor3f(1.0f, 1.0f, 0.0f);
    glPushMatrix();
    glRotatef(rotate, 0.0f, 1.0f, 0.0f);
    glTranslatef(-30.0f, 0.0f, 0.0f);
    glutSolidSphere(6, 15, 15);
    glPopMatrix();

    glColor3f(0.0f,1.0f,0.0f);
    glPushMatrix();
    glRotatef(45, 0.0f, 0.0f, 1.0f);
    glRotatef(rotate, 0.0f, 1.0f, 0.0f);
    glTranslated(50.0f, 0.0f, 0.0f);
    glutSolidSphere(6, 15, 15);
    glPopMatrix();

    glColor3f(0.0f,1.0f,1.0f);
    glPushMatrix();
    glRotatef(-45, 0.0f, 0.0f, 1.0f);
    glRotatef(rotate, 0.0f, 1.0f, 0.0f);
    glTranslated(0.0f, 0.0f, 50.0f);
    glutSolidSphere(6, 15, 15);
    glPopMatrix();

    rotate += 20;
    if(rotate > 360){
        rotate = 0;
    }

    glutSwapBuffers();
}

void SetupRC()
{
    // Black background
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);
}

void TimerFunction(int value)
{
    glutPostRedisplay();
    glutTimerFunc(33, TimerFunction, 1);
}

void ChangeSize(GLsizei w, GLsizei h)
{
    GLdouble nRange = 100.0f;
    GLdouble aspectRatio;

    // O으로 나누지 않도록 함
    if (h == 0)
        h = 1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // 클리핑 영역 설정(left, right, bottom, top, near, far 순서)
    aspectRatio = (GLfloat)w / (GLfloat)h;
    if (w <= h)
        glOrtho(-nRange, nRange, -nRange / aspectRatio, nRange / aspectRatio, -nRange, nRange);
    else
        glOrtho(-nRange * aspectRatio, nRange * aspectRatio, -nRange, nRange, -nRange, nRange);

    glMatrixMode(GL_MODELVIEW);  //GL_MODELVIEW : 모델(그리는 물체)에 대한 각각의 좌표계
    glLoadIdentity();   //좌표계 초기화(원점)
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Atom");

    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    glutTimerFunc(33, TimerFunction, 1);

    SetupRC();

    glutMainLoop();
    return 0;
}
