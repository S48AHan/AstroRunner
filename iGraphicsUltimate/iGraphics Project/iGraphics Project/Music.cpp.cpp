


#include "iGraphics.h"
#include "bitmap_loader.h"
# include <stdio.h>
# include <iostream>



#define _CRT_NONSTDC_NO_DEPRECATE
#define screenHeight 550
#define screenWidth 900

#define jumplimit 70



void    set();
void	set_m();
void	Enemy_set();
void	Coin_set();
void	Rock_set();


//PauseTimer
int p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14;
bool pause = true;
bool resume;


//IceMage Movement
char IceMage[16][20]={"run\\1.bmp","run\\2.bmp","run\\3.bmp","run\\4.bmp","run\\5.bmp","run\\6.bmp","run\\7.bmp","run\\8.bmp","run\\9.bmp","run\\10.bmp","run\\11.bmp","run\\12.bmp","run\\13.bmp","run\\14.bmp","run\\15.bmp","run\\16.bmp"};
int IMCordinateX=120;
int IMCordinateY=110;
int IMIndex=0;        

//alien er part
char Alien[8][20]={"alien\\alien1.bmp","alien\\alien2.bmp","alien\\alien3.bmp","alien\\alien4.bmp","alien\\alien5.bmp","alien\\alien6.bmp","alien\\alien7.bmp","alien\\alien8.bmp"};
int AlienCordinateX=800;
int AlienCordinateY=110;
int AlienIndex=0; //alien er index
bool AlienKill=false;
int AlienSpeed=10;
int enemyspeed=10;

// coin part
int coinCordinateX=600;
int coinCordinateY=140;
int coinspeed=10;

//IceMage Jump
char JumpUp[6][20]={"jump\\1.bmp","jump\\2.bmp","jump\\3.bmp","jump\\4.bmp","jump\\5.bmp","jump\\6.bmp"};
char JumpDown[4][20]={"jump\\7.bmp","jump\\8.bmp","jump\\9.bmp","jump\\10.bmp"};
bool jump=false;
bool jumpUp=false;
int IMCordinateJump=0;
int JumpIndexUp=0;
int JumpindexDown=0;

//rock part
int rockCordinateX=700;
int rockCordinateY=screenHeight;
int rockWidth=60;
int rockHeight=60;
int rockspeed=10;



//Music
bool musicOn = true;
bool music=true;
int k=0;


//background poperties
char bg1[10][20]={"road\\road1.bmp","road\\road2.bmp","road\\road3.bmp","road\\road4.bmp","road\\road5.bmp","road\\road6.bmp","road\\road7.bmp","road\\road8.bmp","road\\road9.bmp","road\\road10.bmp"};
char bg2[10][20]={"bg2\\m1.bmp","bg2\\m2.bmp","bg2\\m3.bmp","bg2\\m4.bmp","bg2\\m5.bmp","bg2\\m6.bmp","bg2\\m7.bmp","bg2\\m8.bmp","bg2\\m9.bmp","bg2\\m10.bmp"};
int mountainSpeed= 4;
int RoadSpeed=20;


struct background{
	int x;
	int y;
};

background UpperBackground[10];
background MBackground[10];


//score
int score=0;
char sc[50];

//Health
int health=100;
char hlth[50];

//shoot
int shoot_index=0;
int count_shoot=0;
struct power
{
	int x;
	int y;
	bool show;
}beam[100],enemy[3],coin[3], rock[3];

bool shoot=false;
bool run= true;

//coillition
void Collision(){

	for(int i=0;i<100;i++){
		if(beam[i].x>900){
			beam[i].x=NULL;
			beam[i].y=NULL;
			beam[i].show=false;
			continue;
		}
		for(int j=0;j<3;j++){
			if((beam[i].x>=enemy[j].x && beam[i].x<=enemy[j].x+72) && (beam[i].y>=enemy[j].y && beam[i].y<=enemy[j].y+98)&&(beam[i].show!=false)){

				beam[i].x=NULL;
				beam[i].y=NULL;
				enemy[j].x=900+(rand()%200);
				enemy[j].y = 110;
				beam[i].show=false;
				
			}
			if(enemy[j].x <= IMCordinateX){

				enemy[j].x=900+(rand()%200);
				enemy[j].y = 110;
				health-=20;
				mciSendString("play Music\\Collision.wav", NULL, 0, 0);
			}

		}

	}

	for(int i=0;i<100;i++){
		for(int j=0;j<3;j++){
			if((beam[i].x>=rock[j].x && beam[i].x<=rock[j].x+72) && (beam[i].y>=rock[j].y && beam[i].y<=rock[j].y+60)){

				beam[i].x=NULL;
				beam[i].y=NULL;
				rock[j].x=500+(rand()%900);
				rock[j].y=screenHeight+(rand()%300);
				beam[i].show=false;
				
			}


		}

	}
	for(int j=0;j<3;j++){
		if((IMCordinateX+72>=coin[j].x && IMCordinateX<=coin[j].x+60) && (IMCordinateY+98>=coin[j].y && IMCordinateY<=coin[j].y+60)){

			coin[j].x=900+(j*100)+(rand()%200);
			coin[j].y=120+(rand()%100);
			score+=10;
			mciSendString("play Music\\Collition.wav", NULL, 0, 0);
		}
	}


	for(int j=0;j<3;j++){
		if((IMCordinateX+72>=rock[j].x && IMCordinateX<=rock[j].x+60) && (IMCordinateY+98>=rock[j].y && IMCordinateY<=rock[j].y+60)){


			rock[j].x=500+(j*100)+(rand()%300);
			rock[j].y=550+(rand()%500);
			health-=20;
			mciSendString("play Music\\Collision.wav", NULL, 0, 0);
		}


	}

}




void iDraw()
{

	iClear();

	printf("%d",k);

	if(k!=3){

	mciSendString("close Music\\Background.wav", NULL, 0, 0);

	}
	if(!pause){

	mciSendString("close Music\\play2.wav", NULL, 0, 0);

	}
	if(k==3){

	mciSendString("close Music\\play2.wav", NULL, 0, 0);

	}


	if(k==0)
	{

		iShowBMP(0,0,"front.bmp");
		iText(5,5,"press F9 to continue",(void*)5U);
		 mciSendString("play Music\\play2.wav", NULL, 0, 0);
	}

	else if(k==1)
	{
		iShowBMP(0,0,"story.bmp");
		iText(5,5,"press F9 to skip",(void*)5U);
		 mciSendString("play Music\\play2.wav", NULL, 0, 0);
	}

	else if(k==2)
	{
		iShowBMP(0,0,"menu.bmp");
		mciSendString("play Music\\play2.wav", NULL, 0, 0);

	}


	else if(k==4)
	{
		iShowBMP(0,0,"resume.bmp");
		
	}


	else if(k==3)
	{
		mciSendString("close Music\\play2.wav", NULL, 0, 0);
	
		mciSendString("play Music\\Background.wav", NULL, 0, 0);

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



		//enemy show
		for(int i=0;i<3;i++){
			iShowBMP2(enemy[i].x,enemy[i].y,Alien[AlienIndex],0);

		}

		//coin show
		for(int i=0;i<3;i++){

			iShowBMP2(coin[i].x,coin[i].y,"coin\\coin1.bmp",0);


		}

		//rock show
		for(int i=0;i<3;i++){

			iShowBMP2(rock[i].x,rock[i].y,"rock\\rock3.bmp",0);


		}


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

		//shoot
		for( int i = 0; i < 100; i++)
		{ 
			if(beam[i].show)
			{
				iShowBMP2(beam[i].x,beam[i].y,"power\\1.bmp",0);
				/*	printf("index=%d\n",i);
				printf("beam[%d].x=%d  beam[%d].y=%d",i,beam[i].x,i,beam[i].y);*/
			}

		}


		Collision();


		//white bar for points
		iSetColor(255,255,255);
		iFilledRectangle(0,0,100,550);

		//score show
		iSetColor(0,0,0);
		iText(20,450,"Score:");
		iText(20,400,itoa(score,sc,10),GLUT_BITMAP_HELVETICA_18);

		//score health

		if(health>0){
			iSetColor(0,0,0);
			iText(20,300,"Health:");
			iText(20,350,itoa(health,hlth,10),GLUT_BITMAP_HELVETICA_18);
			iRectangle(50,100,20,100);
			iSetColor(50,205,50);
			iFilledRectangle(50,100,20,health);
		}
		else
		{
			k=2;

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
	printf("%d %d\n",mx,my);

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(k==2)
		{
			if(mx>=253 && mx<=625 && my>=400 && my<=476)
			{

				k=3;
				set();
				set_m();
				Enemy_set();
				Coin_set();
				Rock_set();
				health=100;
				score=0;
				rockspeed=10;
				coinspeed=10;
				enemyspeed=10;
				for(int i=0;i<100;i++){
					beam[i].show=false;
				}

				IMCordinateX=120;
				IMCordinateY=110;
			}
			

		}





		if(k==2)
		{
			if(mx>=253 && mx<=625 && my>=65 && my<=132)
			{
				exit(0);
			}

		}

		if(k==4)
		{
			if(mx>=275 && mx<=625 && my>=420 && my<=495)
			{ 
				pause=true;
				if(pause){
					iResumeTimer(p1);
					iResumeTimer(p2);
					iResumeTimer(p3);
					iResumeTimer(p4);
					iResumeTimer(p5);
					iResumeTimer(p6);
					iResumeTimer(p7);
					iResumeTimer(p8);
					iResumeTimer(p9);
					iResumeTimer(p10);
					iResumeTimer(p11);
					iResumeTimer(p12);
					iResumeTimer(p13);
					iResumeTimer(p14);
					PlaySound(0,0,0);
					k--;
					mciSendString("close Music\\play1.wav", NULL, 0, 0);
					mciSendString("play Music\\Background.wav", NULL, 0, 0);
					//PlaySound(TEXT("Music\\play2.wav"), NULL, SND_LOOP | SND_ASYNC);
				}
			}

		}
		if(k==4)
		{
			if(mx>=284 && mx<=625 && my>=315 && my<=393)
			{
				k-=2;
				pause=true;
				if(pause){
					iResumeTimer(p1);
					iResumeTimer(p2);
					iResumeTimer(p3);
					iResumeTimer(p4);
					iResumeTimer(p5);
					iResumeTimer(p6);
					iResumeTimer(p7);
					iResumeTimer(p8);
					iResumeTimer(p9);
					iResumeTimer(p10);
					iResumeTimer(p11);
					iResumeTimer(p12);
					iResumeTimer(p13);
					iResumeTimer(p14);
					PlaySound(0,0,0);
					PlaySound(TEXT("Music\\play2.wav"), NULL, SND_LOOP | SND_ASYNC);
				}
				set();
				set_m();
				Enemy_set();
				Coin_set();
				Rock_set();
				health=100;
				score=0;
				rockspeed=10;
				coinspeed=10;
				enemyspeed=10;
				for(int i=0;i<100;i++){
					beam[i].show=false;
				}

				IMCordinateX=120;
				IMCordinateY=110;
			}

		}

		if(k==4)
		{
			if(mx>=284 && mx<=625 && my>=90 && my<=172)
			{
				exit(0);
			}

		}

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


	if(key == 's')
	{
		shoot=true;
		run= false;


		beam[shoot_index].show=true;
		if(shoot_index < 100)
		{
			beam[shoot_index].x=IMCordinateX+55;
			beam[shoot_index].y=IMCordinateY+55+IMCordinateJump;

			shoot_index++;
			if(shoot_index==100)
				shoot_index=0;
		}
		mciSendString("play Music\\Beem.wav", NULL, 0, 0);
	}


	if(k==3 && pause || k==4 && !pause){
		if(key =='p')
		{
			pause=!pause;
			if(!pause){

				iPauseTimer(p1);
				iPauseTimer(p2);
				iPauseTimer(p3);
				iPauseTimer(p4);
				iPauseTimer(p5);
				iPauseTimer(p6);
				iPauseTimer(p7);
				iPauseTimer(p8);
				iPauseTimer(p9);
				iPauseTimer(p10);
				iPauseTimer(p11);
				iPauseTimer(p12);
				iPauseTimer(p13);
				iPauseTimer(p14);

			    PlaySound(0,0,0);
                mciSendString("close Music\\play1.wav", NULL, 0, 0);
				mciSendString("close Music\\Background.wav", NULL, 0, 0);
				PlaySound(TEXT("Music\\play1.wav"), NULL, SND_LOOP | SND_ASYNC);

				k++;

			}
			
		}
		

	}


}


void iSpecialKeyboard(unsigned char key)
{


	if(k==0)
	{
		if(key == GLUT_KEY_F9)
		{
			k++;
		}

	}
	else if(k==1)
	{
		if(key == GLUT_KEY_F9)
		{
			k++;
		}

	}

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


//road set and move
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

//mountain set and move
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


//shoot func
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



//Enemy er kaj

void Enemy_set(){
	int j=0;
	for(int i=0;i<3;i++){
		j+=rand()%500;
		enemy[i].x=AlienCordinateX+j;
		enemy[i].y=AlienCordinateY;

	} 
}


void AlienMove(){
	for(int i=0;i<3;i++){
		enemy[i].x-=enemyspeed;
	}
}


void AlienFunc(){
	AlienIndex++;

	if (AlienIndex>=8)
		AlienIndex = 1;
}

void enemyrespawn(){
	for(int i =0;i<3;i++){

		if(enemy[i].x <0){
			enemy[i].x=900+(i*100)+(rand()%200);
		}
	}

}

//coin part moverment functions
void Coin_set(){
	int j=0;
	for(int i=0;i<3;i++){
		j+=rand()%500;
		coin[i].x=coinCordinateX+j;
		coin[i].y=coinCordinateY;

	} 
}

void CoinMove(){
	for(int i=0;i<3;i++){
		coin[i].x-=coinspeed;
	}
}

void Coinrespawn(){
	for(int i =0;i<3;i++){

		if(coin[i].x <0){
			coin[i].x=900+(i*100);
			coin[i].y=120+(rand()%100);
		}
	}

}

void Rock_set(){
	int j=0;
	for(int i=0;i<3;i++){
		j+=(rand()%500);
		rock[i].x=rockCordinateX+j;
		rock[i].y=rockCordinateY;

	} 
}

void Rockrespawn(){
	for(int i =0;i<3;i++){

		if(rock[i].y <=110 ){
			rock[i].x=500+(rand()%900);
			rock[i].y=screenHeight+(rand()%300);

		}
		else{

			rock[i].y-=rockspeed;
			rock[i].x-=rockspeed;
		}
	}

}

void speedrising(){
	rockspeed++;
	coinspeed++;
	enemyspeed++;
	//RoadSpeed++;
	//mountainSpeed++;

}


int main()
{

	set();
	set_m();
	Enemy_set();
	Coin_set();
	Rock_set();

	p1 = iSetTimer(50, change);
	p2 = iSetTimer(50, change_m);

	p3 = iSetTimer(50,jumpFunc);
	p4 = iSetTimer(500,moveUp);
	p5 = iSetTimer(500,moveDown);

	p6 = iSetTimer(75,func);
	p7 = iSetTimer(50, change_shoot);

	p8 = iSetTimer(50,AlienMove);
	p9 = iSetTimer(50,AlienFunc);
	p10 = iSetTimer(50,enemyrespawn);

	p11 = iSetTimer(50,CoinMove);
	p12 = iSetTimer(50,Coinrespawn);

	p13 = iSetTimer(50,Rockrespawn);

	p14 = iSetTimer(10000,speedrising);

	 mciSendString("play Music\\play2.wav", NULL, 0, 0);

	 iInitialize(screenWidth, screenHeight, "Demo");


	iStart(); 

	return 0;
}