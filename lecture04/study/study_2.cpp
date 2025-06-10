#include <GL/glut.h>
#include <math.h>
#include <iostream>

#define GL_PI 3.1415f

// 전역 변수
GLfloat xTran = 0.0f, yTran = 0.0f;
GLfloat xRot = 0.0f, yRot = 0.0f;

// 키보드 입력 함수
void keyboard(unsigned char key, int x, int y) {
    if (key == 'a') xTran -= 2.0f;
    else if (key == 'd') xTran += 2.0f;
    else if (key == 'w') yTran += 2.0f;
    else if (key == 'x') yTran -= 2.0f;
    glutPostRedisplay();
}

// 특수키 입력 함수
void SpecialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_UP) xRot -= 2.0f;
    else if (key == GLUT_KEY_DOWN) xRot += 2.0f;
    else if (key == GLUT_KEY_LEFT) yRot -= 2.0f;
    else if (key == GLUT_KEY_RIGHT) yRot += 2.0f;
    glutPostRedisplay();
}

// 원기둥 렌더링
void RenderScene() {
    float x, y;
    float radius = 50.0f;
    float height = 75.0f;
    bool bCull = true;
    int slices = 32;

    glClear(GL_COLOR_BUFFER_BIT);

    if (bCull) {
        glEnable(GL_CULL_FACE);  // 뒷면 제거 활성화
    }
    else {
        glDisable(GL_CULL_FACE);
    }

    glPushMatrix();
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);  // X축 회전
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);  // Y축 회전

    glTranslated(xTran, 0.0f, 0.0f);  // X축 평행이동
    glTranslated(0.0f, yTran, 0.0f);  // Y축 평행이동


    // 밑면
    glColor3f(1.0f, 0.0f, 0.0f); // 빨강
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, 0.0f, 0.0f); // 중심점
    for (float angle = 0.0f; angle <= 2.0f * GL_PI + 0.1f; angle += (GL_PI / 16.0f)) {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, 0.0f);
    }
    glEnd();

    // 윗면
    glColor3f(0.0f, 0.0f, 1.0f); // 파랑
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, 0.0f, height); // 중심점
    for (float angle = 0.0f; angle <= 2.0f * GL_PI + 0.1f; angle += (GL_PI / 8.0f)) {
        x = radius * sin(angle);
        y = radius * cos(angle);
        glVertex3f(x, y, height);
    }
    glEnd();

    // 원기둥 측면
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLE_STRIP);
    for (float angle = 0.0f; angle <= 2.0f * GL_PI + 0.1f; angle += (GL_PI / 8.0f)) {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, 0.0f);        // 아래쪽 원
        glVertex3f(x, y, height);      // 위쪽 원
    }
    glEnd();

    glPopMatrix();
    glFlush();
}

// 초기화
void SetupRC() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glShadeModel(GL_FLAT);
}

// 창 크기 변경 처리
void changeSize(GLsizei w, GLsizei h) {
    GLfloat t = 100;
    GLfloat wSizeRatio;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    wSizeRatio = (GLfloat)w / (GLfloat)h;
    if (w <= h)
        glOrtho(-t, t, -t / wSizeRatio, t / wSizeRatio, t, -t);
    else
        glOrtho(-t * wSizeRatio, t * wSizeRatio, -t, t, t, -t);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// 메인
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Cylinder");

    SetupRC();
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(SpecialKeys);
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(changeSize);
    glutMainLoop();
}
