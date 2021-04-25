//======================================================================
// Metodos_Grid.cpp
//
// Métodos generales para la implementación correcta de la matriz
//
//======================================================================

#include "Maze_Recursivo.hpp"

//----VARIABLES GLOBALES------------------------------------------------
extern int columnas,filas;
extern unsigned long int k;

//----PEDIMOS LAS DIMENSIONES AL USUARIO--------------------------------
void Pedir(){
    printf("Introduzca dimensiones\n Filas: ");
    scanf("%d", &filas);
    printf(" Columnas: ");
    scanf("%d", &columnas);
    // Se ajustan las dimensiones para que sean impares siempre.
    (filas%2)?filas:filas+=1;
    (columnas%2)?columnas:columnas+=1;
}

//----INICIALIZAMOS LA MATRIZ RESERVANDO MEMORIA Y RELLENANDO CON'#'-----
char **SetGrid(char **grid){
    int i=0,j=0;
    // Se reserva memoria dinámica (del tamaño de "filas").
    grid = (char **) malloc (filas * sizeof(char *)); 
	    if (grid == NULL){
  	        printf("No se pudo reservar memoria\n");
		    // return -1;
        }
    // Se reserva memoria dinámica para cada fila (tamaño de "columnas").
    for (i = 0; i < filas; ++i) {
        grid[i] = (char *) malloc (columnas * sizeof(char));
        if (grid[i] == NULL) {
  	        printf("No se pudo reservar memoria\n");
			// return -1;
  	    }
    }
    // Se inicializa toda la matriz con '#'.
    for (i=0; i<filas; ++i){
        for(j=0; j<columnas; ++j)
            grid[i][j]='#';
    }
    return grid;
}

//----COMPRUEBA SI LA CASILLA A VISITAR ESTÁ DENTRO DE LOS LÍMITES-------
int IsInBounds(int x, int y){
    if (x < 1 || x > (filas-2)) return false;
    if (y < 1 || y > (columnas-2)) return false;
    return true;
}

//----MUESTRA EN CONSOLA EL LABERINTO Y LOS DATOS DE EJECUCIÓN------------
void PrintGrid(char **grid){
    for (int i=0; i<filas; i++) {
        for (int j=0; j<columnas; j++)
            printf("%c",grid[i][j]);
        printf("\n");
    }
    printf("%d ", columnas);
    printf("%d ", filas);
    printf("%ld\n", k); // Muestra el nº de iteraciones.
}

//----LIBERA TODA LA MEMORIA RESERVADA------------------------------------
void Free(char **grid){
    //Se libera la memoria para cada vector fila.
    for (int i = 0; i < filas; ++i)
        free(grid[i]);
    //Se libera memoria para el vector de vectores fila.
    free(grid);
}