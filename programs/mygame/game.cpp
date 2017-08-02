#include<jdgraphics.h>

//#include<GL\glut.h>
#include<cstdlib>

unsigned char temp;

float x=0,y=-4,z=0;
/*
float speed=0;
float acc=+2;
float brake=-1;
*/
float zangle=180;
float xangle=0,yangle=0;
void drawScene0();


void update(int value)
{
    switch(temp)
    {
        case 'q' : {
            x-=0.1;
            break;
        }
        case 's' : {
            y-=0.1;
            break;
        }
        case 'e' : {
            x+=0.1;
            break;
        }
        case 'w' : {
            y+=0.1;
            break;
        }
        case '+' : {
            z+=0.1;
            break;
        }
        case '-' : {
            z-=0.1;
            break;
        }
        case 'a' : {
            zangle+=5;
            break;
        }
        case 'd' : {
            zangle-=5;
            break;
        }
        case 'g':{
                xangle+=1;
                break;
        }
        case 'b':{
            xangle-=1;
            break;
        }
        case 'f':{
            yangle-=1;
            break;
        }

        case 'h':{
            yangle+=1;
            break;
        }
    }
    glutPostRedisplay();
    return;
}

void handleKeypress(unsigned char key,int x,int y)
{
    switch(temp=key)
    {
        case 27  : exit(0);
    }
    glutTimerFunc(5,update,0);
}

void handleResize(int w,int h)
{
    gView(0,0,w,h);
    matProj();
    gReset();
    gluPerspective(45,double(w/h),1,200);
}

void drawScene0()
{
    gClear();
    matMview();
    gReset();


    glTranslatef(0,0.5,-10);
    glTranslatef(x,y,z);

    glRotatef(zangle,0,0,1);
    glRotatef(xangle,1,0,0);
    glRotatef(yangle,0,1,0);

glPushMatrix();
glColor3f(1,0,0);
    glBegin(GL_TRIANGLES);

    glVertex3f(0,-0.5,0);
    glVertex3f(1,0.5,0);
    glVertex3f(-1,0.5,0);

    glEnd();
    glPopMatrix();

glPushMatrix();
glColor3f(0,1,0);
    glBegin(GL_TRIANGLES);

    glVertex3f(0,-0.5,0);
    glVertex3f(-1,0.5,0);
    glVertex3f(0,0,+1);

    glEnd();

    glPopMatrix();

    glPushMatrix();
glColor3f(1,1,1);

    glBegin(GL_TRIANGLES);

    glVertex3f(1,0.5,0);
    glVertex3f(-1,0.5,0);
    glVertex3f(0,0,+1);

    glEnd();

    glPopMatrix();

    glPushMatrix();
glColor3f(0,0,1);

    glBegin(GL_TRIANGLES);

    glVertex3f(1,0.5,0);
    glVertex3f(0,0,+1);
    glVertex3f(0,-0.5,0);


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

    gDraw(drawScene0);
    gKeyb(handleKeypress);
    gResize(handleResize);


    gML();

    return 0;
}






