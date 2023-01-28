# include "iGraphics.h"



/*
	function iDraw() is called again and again by the system.
*/
int i=0;
void iDraw()
{
	//place your drawing codes here

	iClear();

	if(i==0){
	iShowBMP(0,0,"front_pic.bmp");
	}

	if(i==1){
	iShowBMP(0,0,"story.bmp");
	}

	if(i==2){
	iShowBMP(0,0,"menu.bmp");
	}

	/*if(i==3){
	iShowBMP(0,0,"front_pic.bmp");
	}

	if(i==4){
	iShowBMP(0,0,"front_pic.bmp");
	}

	if(i==5){
	iShowBMP(0,0,"front_pic.bmp");
	} */

	
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iPassiveMouse() is called when the user moves the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iPassiveMouse(int mx, int my)
{
	//place your codes here
}


/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	printf("%d %d\n",mx,my);

    /*if(i==0)
	{
	     if(mx>=coordinate && mx<=coordinate && my>=coordinate && my<=coordinate)
		 {
		     i++;
		 }
	
	}
	printf("%d %d\n",mx,my);

    if(i==0)
	{
	     if(mx>=coordinate && mx<=coordinate && my>=coordinate && my<=coordinate)
		 {
		     exit(0);
		 }
	
	}*/
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{    
	
	/*if(key == 'x')
	{
		//do something with 'x'
		exit(0);
	}*/
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
	if(i==0)
	{
		if(key == GLUT_KEY_F9)
		{
			i++;
		}

	}
	else if(i==1)
	{
		if(key == GLUT_KEY_F9)
		{
			i++;
		}

	}


	/*if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	if(key == GLUT_KEY_LEFT)
	{
		pic_x--;
	}
	if(key == GLUT_KEY_RIGHT)
	{
		pic_x++;
	}
	if(key == GLUT_KEY_UP)
	{
		pic_y++;
	}
	if(key == GLUT_KEY_DOWN)
	{
		pic_y--;
	}*/
	//place your codes for other keys here
}

int main()
{
	//place your own initialization codes here.
	
	iInitialize(900, 550, "PictureDemo");
	iStart();
	return 0;
}