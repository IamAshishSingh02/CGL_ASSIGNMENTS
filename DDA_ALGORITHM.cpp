#include<GL/glut.h>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
double X1,Y1,X2,Y2;
int selection=1;

class Line
{
     void LineDDA(void)
     {
          cout<<"DDA"<<endl;
          float dy,dx,step,x,y,k,Xin,Yin;
          dx=X2-X1;
          dy=Y2-Y1;

          if(abs(dx)>abs(dy))
          {
               step=abs(dx);
          }
          else
          {
               step=abs(dy);
          }

          Xin=dx/step;
          Yin=dy/step;
          x=X1;
          y=Y1;
          glBegin(GL_POINTS);
          glVertex2i(x,y);
          glEnd();

          for(k=1;k<=step;k++)
          {
                x+=Xin;
                y+=Yin;
                glBegin(GL_POINTS);
                glVertex2i(x,y);
          }
          glEnd();
          glutPostRedisplay();
          glFlush();
     }
     public:
       static void display()
       {
             Line l;
             switch(selection)
             {
                   case 1: l.LineDDA();
                break;
             }
       }
};

void Init()
{
    glClearColor(0.0,0.0,0.2,0.0);
    glViewport(0,0,640,480);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-500,500,-500,500,-1,1);
}

void lineGeneration(int i)
{
    if(i==27) exit(0);
    selection=i;
}

void keyboard(unsigned char key, int x, int y)
{
    if(key== 27) exit(0);
    else if(key=='d' || key=='D') selection=1;
}

void createMenu()
{
    int s_id=glutCreateMenu(lineGeneration);
    glutAddMenuEntry("DDA Algoritm", 1);
    int m_id=glutCreateMenu(lineGeneration);
    glutAddSubMenu("Algorithm", s_id);
    glutAddMenuEntry("Exit", 4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char **argv)
{
    cout<<"Enter the First Co-ordinates"<<endl;
    cin>>X1>>Y1;
    cout<<"Enter the Second Co-ordinates"<<endl;
    cin>>X2>>Y2;

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("Line Generation");
    Init();
    glutDisplayFunc(Line::display);
    //createMenu();
    glutMainLoop();
    return 0;
}
