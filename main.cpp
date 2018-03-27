#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include <stdlib.h>
#include <fstream>
#include <math.h>
#include "ColorDisplay.h"
#include "console.h"
#include "draw.h"

using namespace std;
void start();
struct myCar{
    int x,y;
    int score=0;
    bool best=false;
    void moveCar(int &x, int &y){
        char key;
        if(kbhit()){
            key=getch();
            if((key=='a' || key =='A' || key==75) && x>46){
                x=x-4;
            }
            else if((key=='d' || key =='D' || key==77)&& x<55){
               x=x+4;
            }
            else if((key=='w' || key=='W' || key==72) && y>2){
                y--;
            }
            else if((key=='s' || key=='S' || key==80) && y<27){
                y++;
            }
            else if(key==32)
                start();
        }
    }
};

struct badCar{
    int x,y=2;
    int speed;
    int calor;
    int rand_calor(){
        srand(time(NULL));
        return rand()%14+2;
    }
    int rand_location(){
        srand(time(NULL));
        return rand()%4*4+46;
    }


     void moveCar(int &y,int &cal){
        y++;
        if(y==28){
            y=1;
            x=rand_location();
            cal=rand_calor();
        }
    }
};

void start(){
    char key='a';
    gotoXY(15,15); cout << "Press space to continue";
    while(1){
        if(kbhit()){
            key=getch();
            if(key==' ') break;
        }
    }
    for(int i=3;i>0;i--){
        ColorCharacter cc;
        COORD pos;
        int x=52,y=15;
        ColorDisplay cd( height , width , {3,2} );
        pos.Y =y-1,pos.X =x,cc.character='1'+i-1,cc.color = i+3,cd.setColorCharacterAtPosition(cc, pos);
        Sleep(1000);
    }
}

 bool crash(myCar& mycar, badCar &badcar){
    if(mycar.x==badcar.x && abs(badcar.y - mycar.y)<=1)  return true;
    else return false;
 }

int bestScore(myCar& mycar){
    int bestscore;
    ifstream infile;
    infile.open("score.txt");
    infile >> bestscore;
    infile.close();
    if(bestscore<mycar.score){
        mycar.best=true;
        ofstream outfile;
        outfile.open("score.txt");
        outfile << mycar.score;
        outfile.close();
        ifstream infile;
        infile.open("score.txt");
        infile >> bestscore;
        infile.close();
    }
    return bestscore;
}

void menu(myCar& mycar, badCar& badcar){
    start();

    badcar.x=50;
    badcar.y=2;
    badcar.calor=5;
    mycar.x=50;
    mycar.y=26;
    mycar.score=0;
    int speed=60;
    int temp=0;
    gotoXY(75,20); cout<< "Scores: "<<mycar.score;
    gotoXY(75,21); cout<< "Best scores: "<<bestScore(mycar)<<endl;
    while(true){

        int x=mycar.x,x1=mycar.y;
        int y=badcar.y;
        mycar.moveCar(mycar.x,mycar.y);
        badcar.moveCar(badcar.y,badcar.calor);
        if(crash(mycar,badcar)){
            break;
        }
        if(mycar.x!=x || mycar.y!=x1) deleteCar(x,x1);
        if(y!=badcar.y) deleteCar(badcar.x,y);
        drawBad_Car(badcar.x,badcar.y,badcar.calor);
        drawMy_Car(mycar.x,mycar.y);
        if(y==27){
            deleteCar(temp,y);
            mycar.score++;
            gotoXY(75,20); cout<< "Scores: "<<mycar.score<<endl;
            gotoXY(75,21); cout<< "Best scores: "<<bestScore(mycar)<<endl;
            if(mycar.score%10==0 && speed>20){
                speed=speed-20;
            }
        }
        temp=badcar.x;
        drawMap();
        Sleep(speed);
    }
    if(mycar.best){
        gotoXY(45,15); cout << "NEW BEST : "<<mycar.score;
    }
    else{
        gotoXY(45,15); cout << "YOUR SCORES : "<<mycar.score;
    }
    gotoXY(45,17); cout << "0 : Exit";
    gotoXY(45,18); cout <<"1 : New game";
    while(!kbhit()){

    }
    char key;
    while(true){
        key=getch();
        if(key=='1' || key =='0')
            break;
    }
    if(key=='1') {
    clrscr();
    menu(mycar,badcar);
    }
    else if(key=='0') return;
}

int main()
{
    myCar mycar;
    badCar badcar;
    menu(mycar,badcar);
}
