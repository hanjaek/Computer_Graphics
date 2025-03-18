#include <GL/freeglut.h>
#include <cmath>

float angle = 0.0f;
float colors[3] = {1.0f, 0.0f, 0.0f};  // 초기 색상 (빨강)

// 색상 업데이트 함수
void updateColor() {
    colors[0] = fabs(sin(angle * 0.1f));
    colors[1] = fabs(cos(angle * 0.1f));
    colors[2] = fabs(sin(angle * 0.1f + 1.5f));
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, 0.0f); // 원점에서 회전
    glRotatef(angle, 0.0f, 0.0f, 1.0f); // 삼각형을 회전

    updateColor(); // 색상 변경

    glBegin(GL_TRIANGLES);
        glColor3f(colors[0], colors[1], colors[2]); glVertex2f(-0.5, -0.5);
        glColor3f(colors[1], colors[2], colors[0]); glVertex2f(0.5, -0.5);
        glColor3f(colors[2], colors[0], colors[1]); glVertex2f(0.0, 0.5);
    glEnd();

    glFlush();
}

// 타이머 함수 (회전)
void timer(int value) {
    angle += 2.0f;
    if (angle > 360.0f) angle -= 360.0f;

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0); // 약 60 FPS
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Rotating Triangle");
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
