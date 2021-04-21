#include "laberinto.hpp"


bool comprobacion (int x, int y, int direccion, char **grid){
    switch (direccion){ 
        case ARRIBA: x -= 1; break;
        case ABAJO: x += 1; break;
        case DERECHA: y += 1; break;
        case IZQUIERDA: y -= 1; break;
    }
    if (grid [x][y] == '#') return true;

    return false;
}

bool esPosible (int x, int y, char ** grid){
    
    int i=0;
    int j=0;
    if (!x || !y || x == sizeof(*grid) || y==sizeof(grid)) return false;
    if (grid [x][y] == ' ') return false;
    
    else{                                    
        for (i=0;i<4;i++){
            j += comprobacion(x,y,i,grid);
        }

        if (j == 3) return true;
    }

    return false;
}

bool isNextPossible (int x, int y, char **grid){

    int i=0;
    // int j=0; no se utiliza verdad?
    if (x>0 && y>0 && x<sizeof(*grid) && y<sizeof(grid)){
        for (i=0;i<4;i++){
            switch (i){
                case ARRIBA: x -= 1; break;
                case ABAJO: x += 1; break;
                case DERECHA: y += 1; break;
                case IZQUIERDA: y -= 1; break;
            }

            if(grid[x][y] == '#'){
                if(esPosible(x, y, grid)) return true;
                printf("\n --- %d, %d \t", x, y);
            }

            else {
                switch (i){
                    case ARRIBA: x += 1; break;
                    case ABAJO: x -= 1; break;
                    case DERECHA: y -= 1; break;
                    case IZQUIERDA: y += 1; break;
                }
            }
        }
    }
    printf("No es posible la siguiente \n");
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

    int i,r, temp, j=0;
    int x=1;
    int y=1;

    int dirs[4];
    dirs[0] = ARRIBA;
    dirs[1] = DERECHA;
    dirs[2] = ABAJO;
    dirs[3] = IZQUIERDA; 

    grid [1][1] = ' ';


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
            switch (dirs[i]){
                case ARRIBA: x -= 1; break;
                case ABAJO: x += 1; break;
                case DERECHA: y += 1; break;
                case IZQUIERDA: y -= 1; break;
            }

            if(esPosible(x,y,grid)) {
                grid [x][y] = ' ';
                printf("\t %d",x);
                printf("\t %d",y);
                printf("\n %d casillas pintadas \n", ++j);
                break;
            }
            switch (dirs[i]){
                case ARRIBA: x += 1; break;
                case ABAJO: x -= 1; break;
                case DERECHA: y -= 1; break;
                case IZQUIERDA: y += 1; break;
            }
        }
        
    }while(isNextPossible(x,y,grid));
}