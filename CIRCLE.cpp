#include<GLUT/glut.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;

int pntX1,pntY1,r;

void plot(int x,int y)
{
     glBegin(GL_POINTS);
     glVertex2i(x+pntX1,y+pntY1);
     glEnd();
}

void muInit(void)
{
     glClearColor(1.0.1.0,1.0,0.0);
     glColor3f(0.0f,0.0f,0.0f);
     glPointSize(4.0);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0,640.0,0.0,480.0);
}

void midPointCircleAlgo()
{
     int x=0;
     int y=r;
     float decision=5/4-r;
     plot(x,y);

     while(y>x)
     {
          if(decision<0)
          {
               x++;
               decision+=2*X+1;
          }
          else
          {
               plot(x,y);
               plot(x,-y);
               plot(-x,y);
               plot(-x,-y);
               plot(y,x);
               plot(-y,x)
               plot(y,-x);
               plot(-y,-x);
          }
          y--;
          x++;
          decision+=2*(x-y)+1;
     }
}

void myDisplay(void)
{
     glClear(GL_COLOR_BUFFER_BIT);
     glColor3f(0.0,0.0,0.0)
     glPointSize(1.0)
     midPointCircleAlgo();
     glFlush();
}

int main(int argc,char** argv)
{
    cout<<"Enter the co-ordinates of the centre: "<<endl;
    cout<<"X-coordinates: ";cin>>pntX1;
    cout<<"\n Y-coordinates: ";cin>>pntY1;
    cout<<"\n Enter Radius: ";cin>>r;
}
