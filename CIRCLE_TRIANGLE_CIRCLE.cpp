#include <GL/glut.h>
#include <cmath>

const float PI=3.14159265358979323846f;
const int CIRCLE_POINTS=700;

void drawCircle(float cx,float cy,float r)
{
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<CIRCLE_POINTS;++i)
    {
        float theta=2.0f*PI*float(i)/float(CIRCLE_POINTS);
        float x=r*cosf(theta);
        float y=r*sinf(theta);
        glVertex2f(cx+x,cy+y);
    }
    glEnd();
}

void drawLine(float x1,float y1,float x2,float y2)
{
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,1.0f,1.0f);
    drawLine(-0.5f,-0.5f,0.5f,-0.5f);
    drawLine(0.5f,-0.5f,0.0f,0.5f);
    drawLine(0.0f,0.5f,-0.5f,-0.5f);
    glColor3f(1.0f,0.0f,0.0f);
    drawCircle(0.0f,-0.15f,0.65f);
    glColor3f(0.0f, 0.0f, 1.0f);
    drawCircle(0.0f,-0.2f,0.3f);
    glFlush();
}

void init()
{
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glColor3f(1.0f,1.0f,1.0f);
    glPointSize(2.0f);
    glLineWidth(2.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutCreateWindow("GLUT Triangle with Circles");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
