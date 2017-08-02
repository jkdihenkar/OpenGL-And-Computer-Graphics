#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>
#include<math.h>
#include<time.h>

#include<jdgraphics.h>
#include<GL/glu.h>
#include<GL/gl.h>

#define len 8192

void printv(va_list args,const char* format);
void print(const char* format, ...);
void printAt(int x,int y,const char* format,...);

double dim = 2;
char* windowname = "jdwindow";

void displayScene()
{
    gClear();
    matProj();
    gReset();

    GLfloat vexA[2] = {0,0.5};
    GLfloat vexB[2] = {0.5,-0.5};
    GLfloat vexC[2] = {-0.5,-0.5};

    GLfloat red[3] = {1,0,0};
    GLfloat blue[3] = {0,0,1};
    GLfloat green[3] = {0,1,0};

    glPointSize(4);

    glBegin(GL_POINTS);

    glColor3fv(red);
    glVertex2fv(vexA);
    glColor3fv(green);
    glVertex2fv(vexB);
    glColor3fv(blue);
    glVertex2fv(vexC);

    glEnd();

    glBegin(GL_LINES);

    glColor3fv(red);
    glVertex2fv(vexA);
    glColor3fv(green);
    glVertex2fv(vexB);

    glColor3fv(blue);
    glVertex2fv(vexC);
    glColor3fv(red);
    glVertex2fv(vexA);

    glColor3fv(green);
    glVertex2fv(vexB);
    glColor3fv(blue);
    glVertex2fv(vexC);

    glEnd();

    glBegin(GL_LINE_STRIP);

    glColor3f(1,1,1);

    glVertex2f(0.7,0.7);
    glVertex2f(0.7,0);
    glVertex2f(0,0.7);

    glEnd();

    glBegin(GL_LINE_LOOP);

    glColor3fv(red);
    glVertex2f(-0.25,-0.25);
    glColor3fv(green);
    glVertex2f(-0.25,-0.15);
    glColor3f(1,1,1);
    glVertex2f(-0.15,-0.15);
    glColor3fv(blue);
    glVertex2f(-0.15,-0.25);

    glEnd();

    float angle;
    int i;

    glBegin(GL_LINE_LOOP);

    for(i=0;i<180;i+=1)
    {
        angle = (2*3.14*i) / 180;
        glVertex2f(cos(angle),sin(angle));

    }

    glEnd();

    glColor3f(1,1,1);

    glLineWidth(3);

    glEnable(GL_LINE_STIPPLE);

    glLineStipple(1, 0x00FF);

    glBegin(GL_LINE_LOOP);

    for(i=0;i<180;i+=1)
    {
        angle = (2*3.14*i) / 180;
        glVertex2f(cos(angle)/10,sin(angle)/10);

    }

    glEnd();




    print("Hello JD...");

    glFlush();

    sBuf();


}

void handleResize(int w,int h)
{
    gView(0,0,w,h);
    matProj();
    gReset();
    float w2h=w/h;
    glOrtho(-dim*w2h,dim*w2h,-dim,dim,-dim,+dim);
    matMview();
    gReset();
}

void handleKeypress(unsigned char key,int x,int y)
{
    switch(key)
    {
        case 27 : exit(0);
    }
}

int main(int argc,char* argv[])
{
    ginit();
    gWindowSize(500,500);
    gWindow(windowname);
    gDraw(displayScene);
    gResize(handleResize);
    gKeyb(handleKeypress);
    glutFullScreen();
    gML();
}


void printv(va_list args,const char* format)
{

    char buf[len];
    char* ch=buf;
    vsnprintf(buf,len,format,args);
    while(*ch)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,*ch++);
    }
}

void print(const char* format, ...)
{
    va_list args;
    va_start(args,format);
    printv(args,format);
    va_end(args);
}

void printAt(int x,int y, const char* format, ...)
{
    va_list args;
//    glWindowPos2iARB(100,200);
    va_start(args,format);
    printv(args,format);
    va_end(args);
}
