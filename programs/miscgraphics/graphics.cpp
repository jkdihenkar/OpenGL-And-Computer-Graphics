#include<jdgraphics.h>
#include<math.h>
#include<stdlib.h>

void handleKeypress(unsigned char key,int x,int y)
{
    switch (key) { case 27 : exit(0); }
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
    angle += 1.5;
    if(angle>360)
    {
        angle-=360;
    }
    glutPostRedisplay();
    glutTimerFunc(15,update,0);
}

void drawScene()
{

    gClear();
    matMview();
    gReset();
    glClearColor(sin(angle),cos(angle),sin(angle),1);
    glPushMatrix();

    glTranslatef(0,0,-3);
    glRotatef(angle,1,0,0);
    glColor3f(1,0,0);
    glBegin(GL_TRIANGLES);

    glVertex3d(0.50,0.50,0);
    glColor3f(1,1,1);
    glVertex3d(0,0,0);
    glColor3f(1,0,0);
    glVertex3d(0.50,0,0);

    glEnd();


    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.25,-0.25,-2);
    glColor3f(0,1,0);
    glRotatef(angle,0,1,0);
    glBegin(GL_TRIANGLES);

    glVertex3d(-0.25,0.25,0);
    glVertex3d(0.25,0.25,0);
    glColor3f(1,1,sin(angle));
    glVertex3d(-0.25,-0.25,0);
    glEnd();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(-0.75,1.25,-5);
    glColor3f(0,0,1);
    glRotatef(angle,0,0,1);
    glBegin(GL_QUADS);

    glVertex3d(-0.75,0.25,0);
    glVertex3d(-0.75,-0.25,0);
    glColor3f(1,1,cos(angle));
    glVertex3d(0.75,-0.25,0);
    glColor3f(1,1,sin(angle));
    glVertex3d(0.75,0.25,0);

    glEnd();

    glPopMatrix();


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





