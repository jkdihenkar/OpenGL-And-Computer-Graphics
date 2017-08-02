#include<cstdio>
#include<jdgraphics.h>
#include<cmath>

using namespace std;

float angle;
float zet=-2;
int turn=0;

void update(int value)
{
    angle+=2;
    if(angle>360)
    {
        angle-=360;
    }
    if(zet<=-8)
    {
        zet=-8;
        turn=1;
    }
    if(zet>=-2)
    {
        zet=-2;
        turn=0;
    }
    if(turn==0&&zet>=-8)
    {
        zet-=0.05;
    }
    else if(turn==1&&zet<=-2)
    {
        zet+=0.05;
    }
    glutPostRedisplay();
    glutTimerFunc(15,update,0);
}

void handleKeypress(unsigned char key,int x,int y)
{
    switch(key)
    {
        case 27 : {
        exit(0);
        }
    }
}

void write()

{

    glPushMatrix();

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,'a');

    glPopMatrix();

    sBuf();

}


void drawScene()
{
    gClear();
    matMview();
    gReset();

    glClearColor(0.6,0,0.4,1);

    glPushMatrix();

    glTranslatef(0,0.25,zet);
    glRotatef(angle,1,0,0);

    glColor3f((1+sin(angle/10))/2,0,0);
    glBegin(GL_POLYGON);

    glVertex3f(-0.5,-0.25,0);
    glVertex3f(+0.5,-0.25,0);
    glVertex3f(0,+0.25,0);
    //glVertex3f(0,-0.5,0);
    glEnd();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0,-0.25,zet);
    glRotatef(angle,0,1,0);
    glColor3f(0,(1+cos(angle/10))/2,0);
    glBegin(GL_POLYGON);

    glVertex3f(-0.5,0.25,0);
    glVertex3f(+0.5,0.25,0);
    glVertex3f(0,-0.25,0);
    //glVertex3f(0,0.5,0);

    glEnd();

    glPopMatrix();

    glPushMatrix();

//not printed
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,'a');

    glPopMatrix();

    //gDraw(write);

    sBuf();


}


void handleResize(int w,int h)
{
    gView(0,0,w,h);
    matProj();
    gReset();
    gluPerspective(45,double(w/h),1,200);

}

int main(int argc,char* argv[])
{
    ginit();
    gWindowSize(400,400);
    gWindow("jd");

    enableG();

    gDraw(drawScene);
    gResize(handleResize);
    gKeyb(handleKeypress);
    glutTimerFunc(15,update,0);
    //glutFullScreen();

    gML();
    return 0;
}







