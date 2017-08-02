#include<GL/glut.h>

#include<cstdlib>

using namespace std;

void handleKeypress(unsigned char key,int x,int y)
{
    switch(key)
    {
        case 27 : exit(0);
    }
}

void initRendering()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);
}

void handleResize(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,(double)w/h,1,200);
}

float angle=-70;

void displayScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0,0,-8);
    GLfloat ambient[] = {0.2,0.2,0.2,1};

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient);

    GLfloat col0[] = {0,0.5,0.5,1};
    GLfloat pos0[] = {4,0,8,1};

    glLightfv(GL_LIGHT0,GL_DIFFUSE,col0);
    glLightfv(GL_LIGHT0,GL_POSITION,pos0);

    GLfloat col1[] = {1,0.2,0.2,1};
    GLfloat pos1[] = {-1,0.5,0.5,0};

    glLightfv(GL_LIGHT1,GL_DIFFUSE,col1);
    glLightfv(GL_LIGHT1,GL_POSITION,pos1);

    glRotatef(angle,0,1,0);

    GLfloat mycol1[] = {1,1,0};

    GLfloat zunit[] = {0,0,1};
    GLfloat xunit[] = {1,0,0};
    GLfloat yunit[] = {0,1,0};

    glColor3fv(mycol1);

    glBegin(GL_QUADS);

    //front
    //glNormal3fv(zunit);
    glNormal3f(-1,0,1);
    glVertex3f(-1.5,-1,1.5);
    glNormal3f(1,0,1);
    glVertex3f(1.5,-1,1.5);
    glNormal3f(1,0,1);
    glVertex3f(1.5,1,1.5);
    glNormal3f(-1,0,1);
    glVertex3f(-1.5,1,1.5);

    //right
    //glNormal3fv(xunit);
    glNormal3f(1,0,-1);
    glVertex3f(1.5,-1,-1.5);
    glNormal3f(1,0,-1);
    glVertex3f(1.5,1,-1.5);
    glNormal3f(1,0,1);
    glVertex3f(1.5,1,1.5);
    glNormal3f(1,0,1);
    glVertex3f(1.5,-1,1.5);

    //back
    //glNormal3f(0,0,-1);
    glNormal3f(-1,0,-1);
    glVertex3f(-1.5,-1,-1.5);
    glNormal3f(-1,0,-1);
    glVertex3f(-1.5,1,-1.5);
    glNormal3f(1,0,-1);
    glVertex3f(1.5,1,-1.5);
    glNormal3f(1,0,-1);
    glVertex3f(1.5,-1,-1.5);

    //left
    //glNormal3f(-1,0,0);
    glNormal3f(-1,0,-1);
    glVertex3f(-1.5,-1,-1.5);
    glNormal3f(-1,0,1);
    glVertex3f(-1.5,-1,1.5);
    glNormal3f(-1,0,1);
    glVertex3f(-1.5,1,1.5);
    glNormal3f(-1,0,-1);
    glVertex3f(-1.5,1,-1.5);

    glEnd();

    glutSwapBuffers();


}

void update(int value)
{
    angle+=1.5;
    if(angle>360)
    {
        angle-=360;
    }
    glutPostRedisplay();
    glutTimerFunc(15,update,1);
}

int main(int argc,char* argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(800,800);
    glutCreateWindow("lighting");

    initRendering();

    glutDisplayFunc(displayScene);
    glutKeyboardFunc(handleKeypress);
    glutReshapeFunc(handleResize);
    glutTimerFunc(25,update,1);

    glutMainLoop();
}









