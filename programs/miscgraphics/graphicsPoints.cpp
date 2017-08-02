#include<cstdio>
#include<jdgraphics.h>
#include<cmath>

using namespace std;

void handleKeypress(unsigned char key,int x,int y)
{
    switch(key)
    {
        case 27 : {
        exit(0);
        }
    }
}

void putpt()
{
    glVertex3f(1,1,-5);
}

void drawScene()
{
    gClear();
    matMview();
    gReset();

    glClearColor(0.6,0,0.4,1);

    glPointSize(10);

    glBegin(GL_POINTS);

    putpt();

    glEnd();

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
    //glutTimerFunc(15,update,0);

    gML();
    return 0;
}
