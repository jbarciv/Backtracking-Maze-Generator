#include "laberinto.hpp"

int main(){
    int i;
    int filas=0;
    int columnas=0;

    printf("Iterativo");

    // Se pide al usuario el tamaño del laberinto.
    printf("Introduzca dimensiones\n Filas: ");
    scanf("%d", &filas);
    printf(" Columnas: ");
    scanf("%d", &columnas); 

    columnas+=2;   // (chema): creo que no tiene por qué hacerse...
    filas+=2; // Añadimos un marco que serán los bordes del laberinto

    char **grid = NULL;
    // Se reserva memoria para el vector de vectores dinámicos (del tamaño de "filas").
    grid = (char **) malloc (filas  * sizeof(char *)); 
    if (grid == NULL) {
        printf("No se pudo reservar memoria\n");
        return -1;
    }
    // Se reserva memoria para cada fila (del tamaño de "columnas").
    for (i = 0; i < filas; ++i) {
        grid[i] = (char *) malloc (columnas * sizeof(char));
        if (grid[i] == NULL) {
            printf("No se pudo reservar memoria\n");
            return -1;
        }
    }

    srand(time(0)); // Generador de numero aleatorio.
    printf("he llegado hasta Srand\n");
    SetGrid(grid, filas, columnas);
    printf("he hecho la grid\n");
    MakeMaze(grid);
    printf("he hecho el laberinto\n"); 
    PrintGrid(grid,filas,columnas);

    // Se libera memoria para cada fila.
    for (i = 0; i < filas; ++i) {
        free(grid[i]);
    }
    free(grid); //Se libera memoria para el vector de vectores ("primera columna").

    system("pause");

    return 0;
}


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
    int ys=0, xs=0;

    int dirs[4];
    dirs[0] = ARRIBA;
    dirs[1] = DERECHA;
    dirs[2] = ABAJO;
    dirs[3] = IZQUIERDA; 

    grid [x][y] = ' ';


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
                case ARRIBA: xs= x-1; break;
                case ABAJO: xs=x+1; break;
                case DERECHA: ys=y+1; break;
                case IZQUIERDA: ys=y-1; break;
            }

            if(esPosible(xs,ys,grid)) {
                grid [xs][ys] = ' ';
                printf("\t %d",xs);
                printf("\t %d",ys);
                printf("\n %d casillas pintadas \n", ++j);
                x=xs;
                y=ys;

                break;
            }
            //  switch (dirs[i]){
            //  case ARRIBA: x += 1; break;
            //  case ABAJO: x -= 1; break;
            //  case DERECHA: y -= 1; break;
            //  case IZQUIERDA: y += 1; break;
            }
        }while(isNextPossible(x,y,grid));
        
    }
