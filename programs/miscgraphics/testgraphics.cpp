#include<jdgraphics.h>

#include<cstdlib>

void handleKeypress(unsigned char key,int x,int y)
{
    switch(key)
    {
        case 'x' : exit(0);
    }
}


void handleResize(int w,int h)
{
    gView(0,0,w,h);
    matProj();
    gReset();
    gluPerspective(45,double(w/h),1,200);
}

float z=-1;

float angle=0;

void update(int num)
{
        z-=0.01;
        angle+=2;

    glutPostRedisplay();
    glutTimerFunc(25,update,0);
}

void drawScene()
{
    gClear();
    matMview();
    gReset();

    glClearColor(1,1,1,1);

    glTranslatef(0,0,-5+z);

    glTranslatef(0.5,0,0);
    glRotatef(angle,0,1,0);
    glColor3f(0,1,0);   //rgb combination
    glBegin(GL_TRIANGLES);

    glColor3f(1,0,0);
    glVertex3f(-0.5,0,0);
    glColor3f(0,1,0);
    glVertex3f(0.5,-1,0);
    glColor3f(0,0,1);
    glVertex3f(0.5,1,0);
    glColor3f(1,1,1);

    glEnd();

    sBuf();
}

int main(int argc,char* argv[])
{
    ginit();

    gWindowSize(500,500);
    gWindow("test");

    enableG();

    gDraw(drawScene);
    gResize(handleResize);
    gKeyb(handleKeypress);
    glutTimerFunc(25,update,0);

    gML();

    return 0;


}
