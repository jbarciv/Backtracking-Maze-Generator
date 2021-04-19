#include <stdio.h>
#include <stdlib.h>

#define ARRIBA 0
#define DERECHA 1
#define ABAJO 2
#define IZQUIERDA 3

void MakeMaze (char **grid, int w, int h){ //la altura h y la anchura w pueden asociarse a una clase...

    int i,r, temp;
    int x, y;

    int dirs[4];
    dirs[0] = ARRIBA;
    dirs[1] = DERECHA;
    dirs[2] = ABAJO;
    dirs[3] = IZQUIERDA; 

    grid [1][1] = ' ';

    x=1;
    y=1;

    do{
        for(i=0;i<4;i++){
            r = rand()%4;
            temp = dirs [r];
            dirs [r] = dirs[i];
            dirs [i] = dirs [r];
        }

        i=0;

        for (i=0;i<4;i++){
            switch (dirs[i]){
                case ARRIBA: y -= 1; break;
                case ABAJO: y += 1; break;
                case DERECHA: x += 1; break;
                case IZQUIERDA: x -= 1; break;
            }

            if(isPossible(x,y,w,h)) break;
            else if (i == 3){
                switch (dirs[3]){
                    case ARRIBA: y += 1; break;
                    case ABAJO: y -= 1; break;
                    case DERECHA: x -= 1; break;
                    case IZQUIERDA: x += 1; break;
                }
                nearestPossible(x,y,w,h);
            }            
        }
        grid [x][y] = ' ';
        i = 0;
    }while(isNextPossible(x,y,w,h) || nearestPossible(x,y));
}