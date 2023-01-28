#include "iGraphics.h"
#include "bitmap_loader.h"
# include <stdio.h>
# include <iostream>


#define screenHeight 550
#define screenWidth 900
#define RoadSpeed 20
#define mountainSpeed 4
#define jumplimit 50




//IceMage Movement
char IceMage[16][20]={"run\\1.bmp","run\\2.bmp","run\\3.bmp","run\\4.bmp","run\\5.bmp","run\\6.bmp","run\\7.bmp","run\\8.bmp","run\\9.bmp","run\\10.bmp","run\\11.bmp","run\\12.bmp","run\\13.bmp","run\\14.bmp","run\\15.bmp","run\\16.bmp"};
//char Shoot[2][20]={""};
int IMCordinateX=120;
int IMCordinateY=110;
int IMIndex=0;
bool jump=false;
bool jumpup=false;
int IMCordinateJump=0;
int count;
int mpos_x,mpos_y;

char bg1[10][20]={"road\\road1.bmp","road\\road2.bmp","road\\road3.bmp","road\\road4.bmp","road\\road5.bmp","road\\road6.bmp","road\\road7.bmp","road\\road8.bmp","road\\road9.bmp","road\\road10.bmp"};
char bg2[10][20]={"bg2\\m1.bmp","bg2\\m2.bmp","bg2\\m3.bmp","bg2\\m4.bmp","bg2\\m5.bmp","bg2\\m6.bmp","bg2\\m7.bmp","bg2\\m8.bmp","bg2\\m9.bmp","bg2\\m10.bmp"};

char IMShoot[20]={"power\\1.bmp"};

struct background{
int x;
int y;
};

background UpperBackground[10];
background MBackground[10];

//shoot
int shoot_index=0;

struct power
{
	int x;
	int y;
	bool show;
}beam[200];


int menu_index=0;
bool shoot=false;
bool run= true;


void iDraw()
{

	iClear();

	if(menu_index==0){
		iShowBMP(0,0,"front_pic.bmp");
	}

	if(menu_index==1){
		iShowBMP(0,0,"story.bmp");
	}

	if(menu_index==2){
		iShowBMP(0,0,"menu.bmp");
	}
	if(menu_index==3){
		iShowBMP(0,150,"bg2\\pbg2.bmp");


		for(int i=0;i<10;i++){
			iShowBMP2(MBackground[i].x,MBackground[i].y,bg2[i],0);

		}

		for(int i=0;i<10;i++){
			iShowBMP(UpperBackground[i].x,UpperBackground[i].y,bg1[i]);

		}


		if(run){

			iShowBMP2(IMCordinateX,IMCordinateY,IceMage[IMIndex],0);
			iSetColor(255,255,255);


		}
		if(shoot){

			iShowBMP2(IMCordinateX,IMCordinateY,"Shoot\\Shoot 1.bmp",0);

			count++;
			if(count==5){
				run= true;
				shoot=false;
				count=0;
			} 


		}


		for( int i = 0; i < 100; i++)
		{
			if(beam[i].show)
			{
				iShowBMP2(beam[i].x,beam[i].y,"power\\1.bmp",0);

			}

		}


		iSetColor(255,255,255);
		iFilledRectangle(0,0,120,550);
	}




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
	if(key == 's')
	{
		shoot=true;
     	run= false;
	
		
			beam[shoot_index].show=true;
			if(shoot_index < 100)
			{
				beam[shoot_index].x=IMCordinateX+55;
				beam[shoot_index].y=IMCordinateY+55;
				
				shoot_index++;
				if(shoot_index==100)
					shoot_index=0;
			}

	}
	
	
		
}


void iSpecialKeyboard(unsigned char key)
{
	/*if(menu_index==0)
	{*/
		if(key == GLUT_KEY_F9)
		{
			menu_index++;
		}

//}
	/*else if(menu_index==1)
	{
		if(key == GLUT_KEY_F9)
		{
			menu_index++;
		}
		

	}
	else if(menu_index==2)
	{
		if(key == GLUT_KEY_F9)
		{
			menu_index++;
		}
	}*/

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

void change_shoot()
{
	for(int i=0;i<100;i++)
	{

		if(beam[i].x>=0 && beam[i].x<=900)
		{
			beam[i].x=beam[i].x+10;
		}

		if(beam[i].x>=900)
		{
		  
			beam[i].show=false;
		}
		
	}

}



int main()
{
	
	set();
	set_m();
	iSetTimer(50, change);
	iSetTimer(50, change_m);
	iSetTimer(75,func);
	iSetTimer(50, change_shoot);
	iInitialize(screenWidth, screenHeight, "Demo");

	iStart(); 

	return 0;
}