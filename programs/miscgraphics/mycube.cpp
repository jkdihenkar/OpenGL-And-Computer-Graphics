#include<jdgraphics.h>

#include<cstdlib>

void handleKeypress(unsigned char key,int x,int y)
{
    switch(key)
    {
        case 27 : exit(0);
    }
}

void handleResize(int w,int h)
{
    gView(0,0,w,h);
    matProj();
    gReset();
    gluPerspective(45,double(w/h),1,200);
}

float angle=0;

void update(int value)
{
    angle+=2;
    if(angle>360)
    {
        angle-=360;
    }
    glutPostRedisplay();
    glutTimerFunc(25,update,0);
}

void drawScene()
{
    gClear();
    matMview();  //matMview() 3d drawing
    gReset();

    glTranslatef(0,0,-2.5);
    glRotatef(angle,1,1,1);
    glColor3f(1,0,0);
    glBegin(GL_QUADS);

    glVertex3f(0,0,0);
    glVertex3f(0,1,0);
    glVertex3f(1,1,0);
    glVertex3f(1,0,0);

    glEnd();

    sBuf();
}

int main(int argc,char* argv[])
{
    ginit();

    gWindowSize(400,400);
    gWindow("jd");

    enableG();

    gDraw(drawScene);
    gKeyb(handleKeypress);
    gResize(handleResize);
    glutTimerFunc(25,update,0);

    gML();
    return 0;

}








