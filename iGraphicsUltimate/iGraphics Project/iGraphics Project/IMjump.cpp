#include "iGraphics.h"
#include "bitmap_loader.h"
# include <stdio.h>
# include <iostream>


#define screenHeight 550
#define screenWidth 900
#define RoadSpeed 50
#define mountainSpeed 5
#define jumplimit 50

//IceMage Movement
char IceMage[16][20]={"run\\1.bmp","run\\2.bmp","run\\3.bmp","run\\4.bmp","run\\5.bmp","run\\6.bmp","run\\7.bmp","run\\8.bmp","run\\9.bmp","run\\10.bmp","run\\11.bmp","run\\12.bmp","run\\13.bmp","run\\14.bmp","run\\15.bmp","run\\16.bmp"};
char IMjump[11][30]={"Jump\\jump 1.bmp","Jump\\jump 2.bmp","Jump\\jump 3.bmp","Jump\\jump 4.bmp","Jump\\jump 5.bmp","Jump\\jump 6.bmp","Jump\\jump 7.bmp","Jump\\jump 8.bmp","Jump\\jump 9.bmp","Jump\\jump 10.bmp","Jump\\jump 11.bmp"}
int IMCordinateX=120;
int IMCordinateY=110;
int IMIndex=0;
bool jump=false;
bool jumpup=false;
int IMCordinateJump=0;

int mpos_x,mpos_y;
//background & road
char bg1[10][20]={"road\\road1.bmp","road\\road2.bmp","road\\road3.bmp","road\\road4.bmp","road\\road5.bmp","road\\road6.bmp","road\\road7.bmp","road\\road8.bmp","road\\road9.bmp","road\\road10.bmp"};
char bg2[10][20]={"bg2\\m1.bmp","bg2\\m2.bmp","bg2\\m3.bmp","bg2\\m4.bmp","bg2\\m5.bmp","bg2\\m6.bmp","bg2\\m7.bmp","bg2\\m8.bmp","bg2\\m9.bmp","bg2\\m10.bmp"};


struct background{
int x;
int y;
};

background UpperBackground[10];
background MBackground[10];


void iDraw()
{
	
	iClear();
	
	iShowBMP(0,150,"bg2\\pbg2.bmp");
	for(int i=0;i<10;i++){
		iShowBMP2(MBackground[i].x,MBackground[i].y,bg2[i],0);

	}

	for(int i=0;i<10;i++){
		iShowBMP(UpperBackground[i].x,UpperBackground[i].y,bg1[i]);

	}

	

	 //iShowBMP2(IMCordinateX,IMCordinateY,IceMage[IMIndex],0);
	 iSetColor(255,255,255);
	 iFilledRectangle(0,0,100,550);

	 if(jump){
	      iShowBMP2(IMCordinateX,IMCordinateY+IMCordinateJump,IMjump[0],0)
	 }
	 else
	 {
		  iShowBMP2(IMCordinateX,IMCordinateY,IceMage[IMIndex],0);
	 }

	 if(IMCordinateX>=(screenWidth-100))
		 IMCordinateX=screenWidth-100;
	 if(IMCordinateX<=100)
		 IMCordinateX=100;
}

void iPassiveMouse(int x, int y)
{
	
}



void iMouseMove(int mx, int my)
{
	
}


void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	
	}
}


void iKeyboard(unsigned char key)
{
	if( key ==' ')
	{
		if(!jump){
			jump=true;
		
		}
	}
}


void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	if(key == GLUT_KEY_RIGHT)
	{
		IMCordinateX+=10;
	}
	if(key == GLUT_KEY_LEFT)
	{
		IMCordinateX-=10;
	}
	
	
}
//road
void set(){
	int sum=0;
	for(int i=0;i<10;i++){
		UpperBackground[i].y=0;
		UpperBackground[i].x=sum;
		sum+=100;
	   
	}

}
void change(){
	for(int i =0;i<10;i++){
	UpperBackground[i].x -=RoadSpeed;
	if(UpperBackground[i].x <0){
	   UpperBackground[i].x=screenWidth+50;
	   }
	}

}

//mountain
void set_m(){
	int sum=0;
	for(int i=0;i<10;i++){
		MBackground[i].y=145;
		MBackground[i].x=sum;
		sum+=100;
	   
	}

}
void change_m(){
	for(int i =0;i<10;i++){
	MBackground[i].x -=mountainSpeed;
	if(MBackground[i].x <0){
	   MBackground[i].x=screenWidth+90;
	   }
	}

}


void func(){
IMIndex++;

if (IMIndex>=14)
	IMIndex = 1;
}


int main()
{
	
	set();
	set_m();
	iSetTimer(50, change);
	iSetTimer(50, change_m);
	iSetTimer(75,func);

	iInitialize(screenWidth, screenHeight, "Demo");

	iStart(); 

	return 0;
}