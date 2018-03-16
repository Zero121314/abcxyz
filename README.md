# abcxyz
#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<string>
#include<ctime>
#include "console.h"
#define leftroad  15
#define rightroad  55
#define Hieght 27 
using namespace std;
void gotoXY (int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;                  
	HANDLE	hConsoleOut;
	COORD	Home = {0,0};
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}
enum trangthai{UP,DOWN,LEFT,RIGHT,STOP};
struct car{
	int x,y;
	trangthai tt;
};

void xuly(trangthai & tt){
	
	char key;
			tt=STOP;
	if(kbhit()){
			key=getch();
			if(key=='w' || key=='W')	tt=UP;
			else if(key=='s' || key=='S')	tt=DOWN;
			else if(key=='a' || key=='A')	tt=LEFT;
			else if(key=='d' || key=='D')	tt=RIGHT;
		}
}
int vatcan(){
	srand(time(NULL));
	return (rand()%(rightroad-leftroad-4)+14);	
}
int Endgame(int vatcanx,int vatcany,int xex, int xey){
	if(vatcanx>=xex-3 && vatcanx<=xex && vatcany<=xey && vatcany>=xey-3)
	{
		return 1;
	}
	return 0;
}

void inxe(int x, int y){
	for(int i=0;i<3;i++){
			gotoXY(x,y+i);
			cout << "!!!!";
		}
}
void in(trangthai tt,int x, int y){
		car can;
		car xe;
		can.x=22,can.y=0;
		xe.x=x,xe.y=y;
		while(1){
		if(Endgame(can.x,can.y,xe.x,xe.y)==1){
			clrscr();
			cout << "Gameover";
			break;
		}
		  clrscr();
		xuly(tt);
		if(can.y==Hieght){
			can.x=vatcan();
			can.y=0;
		}
		inxe(can.x,can.y);
		inxe(xe.x,xe.y);
		{
			if(tt==UP)			xe.y--;
			else if(tt==DOWN)	xe.y++;
			else if(tt==LEFT)	xe.x--;
			else if(tt==RIGHT)	xe.x++;
			else				xe.x=xe.x;
			if(xe.x==leftroad-1)	xe.x++;
			else if(xe.x==rightroad-3)	xe.x--;
			else if(xe.y==-1)		xe.y++;
			else if(xe.y==Hieght+1)	xe.y--;
		}
		can.y++;
		{
			int bientrai=leftroad,bienphai=rightroad;
			for(int l=0;l<=Hieght+2;l++){
				gotoXY(bientrai-1,l);	cout << "I";
				gotoXY(bienphai+1,l);	cout << "I";
			}	
		}
		Sleep(40);
		
	}
}

int main(){
	car A;
	A.x=(leftroad+rightroad)/2;
	A.y=Hieght/2;
	in(A.tt,A.x,A.y);

}
