#include "LaberintoHeader.hpp"

extern unsigned int nfilas;
extern unsigned int ncol;

/*
esPosible() comprueba si una casilla es apta para derribar un muro #
es decir, para convertir una casilla tipo muro (#) en pasillo ( )
*/

bool esPosible(unsigned int* fila, unsigned int* col,char** grid,int dir){
    
    if(isOnBounds(*fila,*col)) return false;
    else{
        cambioCasilla(fila,col,dir, ADELANTE);

        if (isOnBounds(*fila, *col)) {
            cambioCasilla(fila, col, dir, ATRAS);
            return false;
        }

        if (comprobacion(fila, col, grid)) return true;

        cambioCasilla(fila, col, dir, ATRAS);
    }
    return false;
}

//isOnBounds() comprueba si un elemento esta EN los bordes del laberinto

bool isOnBounds (unsigned int fila, unsigned int col) {
    if (!fila || !col || fila==(nfilas-1) || col==(ncol-1)) return true;

    return false;
}

//comprobacion() comprueba si una casilla muro(#) esta rodeada de muros(#)

bool comprobacion (unsigned int* fila, unsigned int*col, char** grid){
    int i, j=0;

    for (i=0;i<4;i++){
        cambioCasilla(fila,col,i,ADELANTE);

        if (isOnBounds(*fila,*col)) {
            cambioCasilla(fila,col,i,ATRAS);
            continue;
        }

        j+=(grid [*fila][*col] == MURO);
        cambioCasilla(fila,col,i,ATRAS);
    }

    if (j>=3) return true;

    return false;
}

//cambioCasilla avanza o retrocede casillas segun la variable tipoAvance

bool cambioCasilla (unsigned int* fila, unsigned int* col, int direccion, bool tipoAvance){
    
    /*
    tipoAvance regula el tipo de avance que se produce:
        Si tipoAvance = ADELANTE == 1, la casilla avanza en la direccion indicada.
        Si tipoAvance = ATRAS == 0, la casilla retrocede en la direccion indicada.    
    */

    if (tipoAvance){
        switch (direccion){
            case ARRIBA: *fila -= 1;break;
            case DERECHA: *col += 1;break;
            case ABAJO: *fila += 1;break;
            case IZQUIERDA: *col -= 1;break;
        }
    }
    else {
        switch (direccion){
            case ARRIBA: *fila += 1;break;
            case DERECHA: *col -= 1;break;
            case ABAJO: *fila -= 1;break;
            case IZQUIERDA: *col += 1;break;
        }
    }
}

//La funcion control establece la condicion de salida del bucle principal

bool control (unsigned int fila, unsigned int col, char** grid){
    
    int j=0;

    for (j=0;j<4;j++){
        if(esPosible(&fila, &col, grid, j)) return true;
    }
    // Si la siguiente casilla puede ser cambiada por ' ' (esto es, derribar un muro),
    // el bucle continua
    
    return false;
}



void SetGrid(char **grid, int filas, int columnas){
    // Rellenamos la malla con carácter '#'.
    int i,j;// vuelvo a quitar el unsigned... pues al comparar filas y columnas (que son int) con i y j que son unsigned da un warning...
    for (i=0; i<filas; ++i){
        for(j=0; j<columnas; ++j){
            // if (!i && j==1) grid[i][j]=' '; //Casillas de entrada y salida. (falta la de salida)
            //  else grid[i][j]='#';
            grid[i][j]= MURO; // por ahora lo rellenamos todo luego ya hacemos e/s
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

void MakeMaze (char** grid){
    
    int i, r;
    unsigned int l, m;
    int temp;
    unsigned int fila = 1;
    unsigned int col = 1;

    int dirs[4];
    dirs[0] = ARRIBA;
    dirs[1] = DERECHA;
    dirs[2] = ABAJO;
    dirs[3] = IZQUIERDA;

    for (l=1;l<nfilas-1;l++){
        for(m=1;m<ncol-1;m++){
            fila = l;
            col = m;
            do{
                for (i=0;i<4;i++){
                    r = rand()%4;
                    temp = dirs[r];
                    dirs[r] = dirs[i];
                    dirs[i] = temp;
                }
                
                for (i=0;i<4;i++){
                    if (!isOnBounds(fila,col) && esPosible(&fila, &col, grid, dirs [i])){
                        grid [fila][col] = PASILLO;
                        break; 
                    }
                }

                printf("\n\t %u, %u",fila, col);
            }while(control(fila, col, grid));
        }
    }
}
