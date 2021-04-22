#include "laberinto.hpp"

bool esPosible2(unsigned int*,unsigned int*,int, char**);
bool control (unsigned int, unsigned int, char**);
bool comprobacion2 (int, int, int, char**, int);

void SetGrid(char **grid, int filas, int columnas){
    // Rellenamos la malla con carácter '#'.
    int i,j;// vuelvo a quitar el unsigned... pues al comparar filas y columnas (que son int) con i y j que son unsigned da un warning...
    for (i=0; i<filas; ++i){
        for(j=0; j<columnas; ++j){
            // if (!i && j==1) grid[i][j]=' '; //Casillas de entrada y salida. (falta la de salida)
            //  else grid[i][j]='#';
            grid[i][j]='#'; // por ahora lo rellenamos todo luego ya hacemos e/s
        }
    }
}

void PrintGrid(char **grid, int filas, int columnas){
 // Muestra el laberinto final en la consola. 
    for (int i=0; i<filas; ++i) { // de nuevo quito el unsigned
        for (int j=0; j<columnas; ++j)
            printf("%c",grid[i][j]);
        printf("\n");
    }
}

bool control (unsigned int fila, unsigned int col, char** grid){
    int i=0;

    for(i=0;i<4;i++){
        if(esPosible2(&fila, &col, i, grid)) return true;
    }
    return false;
}

bool comprobacion2(int fila, int col, int direccion, char** grid, int *j){
    switch (direccion){
        case ARRIBA: fila -= 1; break;
        case ABAJO: fila += 1; break;
        case DERECHA: col += 1; break;
        case IZQUIERDA: col -= 1; break;
    }

    if(grid [fila][col] == '#'){
        *j++;
        return true;
    }

    return false;
}

bool esPosible2(unsigned int* fila, unsigned int* col, int direccion, char** grid){
    
    int i=0;
    int j=0;

    printf(" %d %d ", *fila, *col);
    if(!(*fila) || !(*col) || *fila == 11 || *col == 11) return false;
    
    else{
        switch (direccion){
            case ARRIBA: fila -= 1; break;
            case ABAJO: fila += 1; break;
            case DERECHA: col += 1; break;
            case IZQUIERDA: col -= 1; break;
        }
        if(!(*fila) || !(*col) || *fila == 11 || *col == 11){
            switch (direccion){
                case ARRIBA: fila += 1; break;
                case ABAJO: fila -= 1; break;
                case DERECHA: col -= 1; break;
                case IZQUIERDA: col += 1; break;
            }
            return false; 
        }
        else if (grid [*fila][*col] == ' ') return false;
        
        for (i=0;i<4;i++){
            
            comprobacion2(*fila,*col, i, grid, &j);

            printf("\t %d", j);
            
            if (j==2)return true;
        }

        switch (direccion){
            case ARRIBA: fila += 1; break;
            case ABAJO: fila -= 1; break;
            case DERECHA: col -= 1; break;
            case IZQUIERDA: col += 1; break;
        }
        return false;
    }
    printf("yo no deberia estar...");
}

void MakeMaze (char** grid){

    unsigned int fila, col, i;
    int r,temp;

    int dirs[4];
    dirs[0] = ARRIBA;
    dirs[1] = DERECHA;
    dirs[2] = ABAJO;
    dirs[3] = IZQUIERDA; 

    grid [1][1] = ' ';

    fila=1;
    col=1;

    do{
        for(i=0;i<4;i++){
            r = rand()%4;
            temp = dirs[r];
            dirs[r] = dirs[i];
            dirs[i] = temp;
        }
        for(i=0;i<4;i++) printf("%d,",dirs[i]);
        printf("\n");

        for (i=0;i<4;i++){
            printf("\n llego...");
            if(esPosible2(&fila, &col, dirs[i], grid)) grid[fila][col] = ' ';
        }
    }while (control(fila,col, grid));
}
