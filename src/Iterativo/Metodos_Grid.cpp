///======================================================================
// Metodos_Grid.cpp
//
// Funciones que definen la matriz del laberinto
//
//======================================================================
#include "Maze_Iterativo.hpp"

//----VARIABLES GLOBALES------------------------------------------------
extern int columnas,filas;
extern unsigned long int k;
extern bool pruebas;

//----INICIALIZAMOS LA MATRIZ RESERVANDO MEMORIA Y RELLENANDO CON'#'-----
int SetGrid(char **grid){
    int i=0,j=0;
    // Se reserva memoria dinámica (del tamaño de "filas").
	if (grid == NULL){
  	    printf("No se pudo reservar memoria\n");
	    return -1;
    }
    // Se reserva memoria dinámica para cada fila (tamaño de "columnas").
    for (i = 0; i < filas; ++i) {
        grid[i] = (char *) malloc (columnas * sizeof(char));
        if (grid[i] == NULL) {
  	        printf("No se pudo reservar memoria\n");
			return -1;
  	    }
    }
    // Se inicializa toda la matriz con '#'.
    for (i=0; i<filas; ++i){
        for(j=0; j<columnas; ++j)
            grid[i][j]='#';
    }
    // Se establece la entrada y la salida del laberinto.
    grid[0][1] = ' '; 
    grid[filas-1][columnas-2] = ' ';

    return 0;
}

//----MUESTRA EN CONSOLA EL LABERINTO O LOS DATOS DE EJECUCIÓN-----------
void PrintGrid(char **grid,int argc, char **argv){
    if (!pruebas){ // Se comprueba si se está ejecutando una prueba o no.
        for (int i=0; i<filas; i++) {
            for (int j=0; j<columnas; j++)
                printf("%c",grid[i][j]);
            printf("\n");
        }
    } else{
        printf("%d ", filas);
        printf("%d ", columnas);
        printf("%ld\n", k); // Muestra el nº de iteraciones.
    }
}

//----LIBERA TODA LA MEMORIA RESERVADA------------------------------------
void Free(char **grid){
    //Se libera la memoria para cada vector fila.
    for (int i = 0; i < filas; ++i)
        free(grid[i]);
    //Se libera memoria para el vector de vectores fila.
    free(grid);
}