gML()       -> glutMainLoop() -> transfer the control of the main execution to the graphics card
ginit()     -> Initialize the graphics driver
enableG()   -> Initialize the 3D graphics rendering

gDraw()     -> draw a scene by passing the scene as arguement in func
gKeyb()     -> the keybord control function
gResize()   -> called invoked on the resize of the window

gView(4)    -> how to convert the graphics on the display window
gClear()    -> clear the screen of the window and clearup buffers
gReset()    -> reset the camera perspective ane reload
gTriangle() -> begin drawing the triangle
sBuf()      -> swap the buffers and send the scene to display

gWindow()       -> create the window with the name as parameter passed
gWindowSize()   -> Set the forked window size

matMview()  -> matrix in model view
matProj()   -> matrix in projection mode


-------------------------------------------------------------------

glTranslatef(x,y)  -> translate the camera...

glPushMatrix()  -> push and save the transformation state
glPopMatrix()   -> pop out the recent transformation state

glRotatef(angle,x,y,z)  -> rotate with angle and the axis specified

glScalef(percent in of(x,y,z))  ->changes the entire with dimesio ratio

--------------------------------------------------------------------

void update(int value)
{
    angle += 2;
    if(angle>360)
    {
        angle-=360;
    }
    glutPostRedisplay();
    glutTimerFunc(25,update,0);
}

---------------------------------------------------------------------

glColor3f()
glClearColor()

---------------------------------------------------------------------






