# include "iGraphics.h"
# include <stdio.h>
int pic_x, pic_y;


/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here

	//iClear();

	iShowBMP(0,0,"resume.bmp");

    /*iSetColor(255, 0, 0);
	iFilledRectangle(pic_x , pic_y , 100, 100);

	iSetColor(255, 255, 255);
	iFilledRectangle(pic_x + 40 , pic_y +20 , 20, 60);

	iSetColor(255, 255, 255);
	iFilledRectangle(pic_x + 20 , pic_y +40 , 60, 20);
	 
	iText(50,50,"Press `x' to exit");*/

	
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
	//printf("x= %d  y= %d\n",mx,my);
}

/*
	function iPassiveMouse() is called when the user moves the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iPassiveMouse(int mx, int my)
{
	//place your codes here
	//printf("x= %d  y= %d\n",mx,my);
}


/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("Left x=%d  y=%d\n",mx,my);
		//place your codes here
	}
	/*if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		printf("Right x=%d  y=%d\n",mx,my);
		//place your codes here
	}*/
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'x')
	{
		//do something with 'x'
		exit(0);
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	if(key == GLUT_KEY_LEFT)
	{
		pic_x=pic_x-10;
	}
	if(key == GLUT_KEY_RIGHT)
	{
		pic_x=pic_x+10;
	}
	if(key == GLUT_KEY_UP)
	{
		pic_y=pic_y+10;
	}
	if(key == GLUT_KEY_DOWN)
	{
		pic_y=pic_y-10;
	}
	//place your codes for other keys here
}

int main()
{
	//place your own initialization codes here.
	/*pic_x = 300;
	pic_y = 250;*/
	iInitialize(900, 550 , "PictureDemo With S48Ahan");
	iStart();
	return 0;
}
