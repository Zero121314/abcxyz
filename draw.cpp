#include "ColorDisplay.h"
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include "draw.h"

void drawMy_Car(int x,int y){
    ColorCharacter cc[7];
    COORD pos[7];
    ColorDisplay cd( height , width , {3,2} );
    pos[0].Y =y-1,pos[0].X =x,cc[0].character='A',cc[0].color = 4,cd.setColorCharacterAtPosition(cc[0], pos[0]);
    pos[1].Y =y,pos[1].X =x,cc[1].character=178,cc[1].color = 4,cd.setColorCharacterAtPosition(cc[1], pos[1]);
    pos[2].Y =y,pos[2].X =x-1,cc[2].character=233,cc[2].color = 4,cd.setColorCharacterAtPosition(cc[2], pos[2]);
    pos[3].Y =y,pos[3].X =x+1,cc[3].character=233,cc[3].color = 4,cd.setColorCharacterAtPosition(cc[3], pos[3]);
    pos[4].Y =y+1,pos[4].X =x-1,cc[4].character=234,cc[4].color = 4,cd.setColorCharacterAtPosition(cc[4], pos[4]);
    pos[5].Y =y+1,pos[5].X =x,cc[5].character=252,cc[5].color = 4,cd.setColorCharacterAtPosition(cc[5], pos[5]);
    pos[6].Y =y+1,pos[6].X =x+1,cc[6].character=234,cc[6].color = 4,cd.setColorCharacterAtPosition(cc[6], pos[6]);
}

void deleteCar(int x,int y){
    ColorCharacter cc[7];
    COORD pos[7];
    ColorDisplay cd( height , width , {3,2} );
    pos[0].Y =y-1,pos[0].X =x,cc[0].character=' ',cc[0].color = 1,cd.setColorCharacterAtPosition(cc[0], pos[0]);
    pos[1].Y =y,pos[1].X =x,cc[1].character=' ',cc[1].color = 1,cd.setColorCharacterAtPosition(cc[1], pos[1]);
    pos[2].Y =y,pos[2].X =x-1,cc[2].character=' ',cc[2].color = 1,cd.setColorCharacterAtPosition(cc[2], pos[2]);
    pos[3].Y =y,pos[3].X =x+1,cc[3].character=' ',cc[3].color = 1,cd.setColorCharacterAtPosition(cc[3], pos[3]);
    pos[4].Y =y+1,pos[4].X =x-1,cc[4].character=' ',cc[4].color = 1,cd.setColorCharacterAtPosition(cc[4], pos[4]);
    pos[5].Y =y+1,pos[5].X =x,cc[5].character=' ',cc[5].color = 1,cd.setColorCharacterAtPosition(cc[5], pos[5]);
    pos[6].Y =y+1,pos[6].X =x+1,cc[6].character=' ',cc[6].color = 1,cd.setColorCharacterAtPosition(cc[6], pos[6]);
}

void drawBad_Car(int x,int y,int i){
    ColorCharacter cc[7];
    COORD pos[7];
    ColorDisplay cd( height , width , {3,2} );
    pos[0].Y =y-1,pos[0].X =x,cc[0].character='A',cc[0].color = i,cd.setColorCharacterAtPosition(cc[0], pos[0]);
    pos[1].Y =y,pos[1].X =x,cc[1].character=178,cc[1].color = i,cd.setColorCharacterAtPosition(cc[1], pos[1]);
    pos[2].Y =y,pos[2].X =x-1,cc[2].character=233,cc[2].color = i,cd.setColorCharacterAtPosition(cc[2], pos[2]);
    pos[3].Y =y,pos[3].X =x+1,cc[3].character=233,cc[3].color = i,cd.setColorCharacterAtPosition(cc[3], pos[3]);
    pos[4].Y =y+1,pos[4].X =x-1,cc[4].character=234,cc[4].color = i,cd.setColorCharacterAtPosition(cc[4], pos[4]);
    pos[5].Y =y+1,pos[5].X =x,cc[5].character=252,cc[5].color = i,cd.setColorCharacterAtPosition(cc[5], pos[5]);
    pos[6].Y =y+1,pos[6].X =x+1,cc[6].character=234,cc[6].color = i,cd.setColorCharacterAtPosition(cc[6], pos[6]);
}

void drawMap(){
    ColorCharacter cc[width];
    COORD pos[width];
    ColorDisplay cd( height , width , {44,1} );
    for(int i=1;i<=height+2;i++){
        pos[i].Y =i,pos[i].X =44,cc[i].character=179,cc[i].color =3,cd.setColorCharacterAtPosition(cc[i], pos[i]);
    }
    for(int i=1;i<=height+2;i++){
        pos[i].Y =i,pos[i].X =60,cc[i].character=179,cc[i].color =3,cd.setColorCharacterAtPosition(cc[i], pos[i]);
    }
    for(int i=1;i<=height+2;i++){
        pos[i].Y =i,pos[i].X =48,cc[i].character='.',cc[i].color =9,cd.setColorCharacterAtPosition(cc[i], pos[i]);
    }
    for(int i=1;i<=height+2;i++){
        pos[i].Y =i,pos[i].X =52,cc[i].character='.',cc[i].color =9,cd.setColorCharacterAtPosition(cc[i], pos[i]);
    }
    for(int i=1;i<=height+2;i++){
        pos[i].Y =i,pos[i].X =56,cc[i].character='.',cc[i].color =9,cd.setColorCharacterAtPosition(cc[i], pos[i]);
    }
    for(int i=45;i<=59;i++){
        pos[i].Y =0,pos[i].X =i,cc[i].character=196,cc[i].color =9,cd.setColorCharacterAtPosition(cc[i], pos[i]);
    }
    for(int i=45;i<=59;i++){
        pos[i].Y =29,pos[i].X =i,cc[i].character=196,cc[i].color =9,cd.setColorCharacterAtPosition(cc[i], pos[i]);
    }
     pos[0].Y =0,pos[0].X =44,cc[0].character=218,cc[0].color = 3,cd.setColorCharacterAtPosition(cc[0], pos[0]);
     pos[0].Y =0,pos[0].X =60,cc[0].character=191,cc[0].color = 3,cd.setColorCharacterAtPosition(cc[0], pos[0]);
     pos[0].Y =29,pos[0].X =44,cc[0].character=192,cc[0].color = 3,cd.setColorCharacterAtPosition(cc[0], pos[0]);
     pos[0].Y =29,pos[0].X =60,cc[0].character=217,cc[0].color = 3,cd.setColorCharacterAtPosition(cc[0], pos[0]);
}

