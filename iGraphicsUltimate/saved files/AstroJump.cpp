#include "iGraphics.h"
#include "bitmap_loader.h"
# include <stdio.h>
# include <iostream>


#define screenHeight 550
#define screenWidth 900
#define RoadSpeed 20
#define mountainSpeed 4
#define jumplimit 70

//IceMage Movement
char IceMage[16][20]={"run\\1.bmp","run\\2.bmp","run\\3.bmp","run\\4.bmp","run\\5.bmp","run\\6.bmp","run\\7.bmp","run\\8.bmp","run\\9.bmp","run\\10.bmp","run\\11.bmp","run\\12.bmp","run\\13.bmp","run\\14.bmp","run\\15.bmp","run\\16.bmp"};

//IceMage Jump
char JumpUp[6][20]={"jump\\1.bmp","jump\\2.bmp","jump\\3.bmp","jump\\4.bmp","jump\\5.bmp","jump\\6.bmp"};
char JumpDown[4][20]={"jump\\7.bmp","jump\\8.bmp","jump\\9.bmp","jump\\10.bmp"};

int IMCordinateX=120;
int IMCordinateY=110;
int IMIndex=0;//run er index

bool jump=false;
bool jumpUp=false;
int IMCordinateJump=0;
int JumpIndexUp=0;
int JumpindexDown=0;

int mpos_x,mpos_y;

char bg1[10][20]={"road\\road1.bmp","road\\road2.bmp","road\\road3.bmp","road\\road4.bmp","road\\road5.bmp","road\\road6.bmp","road\\road7.bmp","road\\road8.bmp","road\\road9.bmp","road\\road10.bmp"};
char bg2[10][20]={"bg2\\m1.bmp","bg2\\m2.bmp","bg2\\m3.bmp","bg2\\m4.bmp","bg2\\m5.bmp","bg2\\m6.bmp","bg2\\m7.bmp","bg2\\m8.bmp","bg2\\m9.bmp","bg2\\m10.bmp"};


struct background{
	int x;
	int y;
};

background UpperBackground[10];
background MBackground[10];

//shoot

int totalShoot=0;
bool shoot=false;
bool run= true;
int count_shoot;



void iDraw()
{

	iClear();
	//background part
	iShowBMP(0,150,"bg2\\pbg2.bmp");

	//road part
	for(int i=0;i<10;i++){
		iShowBMP2(MBackground[i].x,MBackground[i].y,bg2[i],0);

	}

	//Mountain part
	for(int i=0;i<10;i++){
		iShowBMP(UpperBackground[i].x,UpperBackground[i].y,bg1[i]);

	}



	//white bar for points
	iSetColor(255,255,255);
	iFilledRectangle(0,0,100,550);



	//jump
	if(jump){

		if(jumpUp && shoot){

			//shoot action with jump up

			    iShowBMP2(IMCordinateX,IMCordinateY+IMCordinateJump,"Shoot\\Shoot 1.bmp",0);
				count_shoot++;
				if(count_shoot==5){
					shoot= false;
					count_shoot= 0;
					run=true;
				}
		

		}

		else if (jumpUp)
		{ 
			for(int i=0;i<6;i++)
			{
				iShowBMP2(IMCordinateX,IMCordinateY+IMCordinateJump,JumpUp[JumpIndexUp],0);


			}
		}


		else 
		{
			if(shoot)
			{
				    //shoot action with jump down
				
					iShowBMP2(IMCordinateX,IMCordinateY+IMCordinateJump,"Shoot\\Shoot 1.bmp",0);
					count_shoot++;
					if(count_shoot==5){
						shoot= false;
						count_shoot= 0;
						run =true;
					
				}
			}
			else{
				for(int i=0;i<4;i++)
				{
					iShowBMP2(IMCordinateX,IMCordinateY+IMCordinateJump,JumpDown[JumpindexDown],0);

				}
			}

		}


	}

	else{


		if(run){

			iShowBMP2(IMCordinateX,IMCordinateY,IceMage[IMIndex],0);



		}
		if(shoot){

			iShowBMP2(IMCordinateX,IMCordinateY,"Shoot\\Shoot 1.bmp",0);
			count_shoot++;
			if(count_shoot==5){
				run= true;
				shoot= false;
				count_shoot= 0;
			}

		}
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
	if(key == ' '){
	
		if(!jump){
		jump=true;
		jumpUp=true;
		      }
        }
	if(key == 's'){
	    run= false;
	    shoot=true;
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

void moveUp(){
	JumpIndexUp++;

	if(JumpIndexUp>=6)
	{
		JumpIndexUp=0;
	}
}

void moveDown(){
	JumpindexDown++;

	if(JumpindexDown>=3){
		JumpindexDown=0;
	}
}
void jumpFunc(){
	if(jump){
		if(jumpUp){
			IMCordinateJump+=5;
			if(IMCordinateJump >= jumplimit){

				jumpUp=false;

			}
		}
		else 
		{

			IMCordinateJump-=5;
			if(IMCordinateJump <= 0){

				jump=false;
			}
		}
	}

}

int main()
{

	set();
	set_m();
	iSetTimer(50, change);
	iSetTimer(50, change_m);
	iSetTimer(50,jumpFunc);
	iSetTimer(500,moveUp);
	iSetTimer(500,moveDown);
	iSetTimer(75,func);


	iInitialize(screenWidth, screenHeight, "Demo");

	iStart(); 

	return 0;
}