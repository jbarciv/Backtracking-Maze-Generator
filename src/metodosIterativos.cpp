#include "laberinto.hpp"
// creo que si pones bool tienes que retornar true o false (no 0 o 1...eso sería para enteros)
bool comprobacion (int x, int y, int direccion, char **grid){
    switch (direccion){ // ¿dónde se declara dirección?
        case ARRIBA: y -= 1; break;
        case ABAJO: y += 1; break;
        case DERECHA: x += 1; break;
        case IZQUIERDA: x -= 1; break;
    }
    if (grid [x][y] == '#' || grid [x][y] == '$') return true;

    return false;
}

bool esPosible (int x, int y, char ** grid){
    
    int i=0;
    int j=0;                             // he puesto ' ' pues lo del '$' no lo entiendo...
    if (grid[x][y] == ' ') return false; // ¿es una asignación o comparación?
                                        
    for (i=0;i<4;i++){
        j += comprobacion(x,y,i,grid);
    }

    if (j == 3) return true;

    return false;
}

bool isNextPossible (int x, int y, char **grid){

    int i=0;
    // int j=0; no se utiliza verdad?

    for (i=0;i<4;i++){
        switch (i){
            case ARRIBA: y -= 1; break;
            case ABAJO: y += 1; break;
            case DERECHA: x += 1; break;
            case IZQUIERDA: x -= 1; break;
        }

        if(grid[x][y] == '#'){
            if(esPosible(x, y, grid)) return true;
        }
    }
    //creo que aquí es necesario un return...
    return false;

}

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

void MakeMaze (char **grid){ // podríamos dejarle el mismo nombre que en el otro (chema)

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
            temp = dirs[r];
            dirs[r] = dirs[i];
            // dirs [i] = dirs [r]; creo que está mal...pues temp no lo estás utilizando
            dirs[i] = temp;
        }

        for(i=0;i<4;i++) printf("%d,",dirs[i]);
        printf("\n")

        i=0; //no entiendo muy bien que hace...

        for (i=0;i<4;i++){
            switch (dirs[i]){
                case ARRIBA: y -= 1; break;
                case ABAJO: y += 1; break;
                case DERECHA: x += 1; break;
                case IZQUIERDA: x -= 1; break;
            }

            if(esPosible(x,y,grid)) grid [x][y] = ' ';
        }
        
        i = 0;
    }while(isNextPossible(x,y,grid));
}