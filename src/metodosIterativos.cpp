#include <stdio.h>
#include <stdlib.h>

#define ARRIBA 0
#define DERECHA 1
#define ABAJO 2
#define IZQUIERDA 3

bool comprobacion (int x, int y, int direccion, char **grid){
    switch (direccion){
        case ARRIBA: y -= 1; break;
        case ABAJO: y += 1; break;
        case DERECHA: x += 1; break;
        case IZQUIERDA: x -= 1; break;
    }
    if (grid [x][y] == '#' || grid [x][y] == '$') return 1;

    return 0;
}

bool esPosible (int x, int y, char ** grid){
    
    int i=0;
    int j=0;
    if (grid[x][y] = '$') return 0;

    for (i=0;i<4;i++){
        j += comprobacion(x,y,i,grid);
    }

    if (j == 3) return 1;

    return 0;
}

bool isNextPossible (int x, int y, char **grid){

    int i=0;
    int j=0;

    for (i=0;i<4;i++){
        switch (i){
            case ARRIBA: y -= 1; break;
            case ABAJO: y += 1; break;
            case DERECHA: x += 1; break;
            case IZQUIERDA: x -= 1; break;
        }

        if(grid[x][y] == '#'){
            if(esPosible(x, y, grid)) return 1;
        }
    }

}

void MakeMaze (char **grid){ //la altura h y la anchura w pueden asociarse a una clase...

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

            if(esPosible(x,y,grid)) break;
        }
        grid [x][y] = ' ';
        i = 0;
    }while(isNextPossible(x,y,grid));
}