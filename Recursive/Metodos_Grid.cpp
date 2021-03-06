///======================================================================
// Metodos_Grid.cpp
//
// Funciones que definen la matriz del laberinto
//
//======================================================================

#include "Maze_Recursivo.hpp"

//----VARIABLES GLOBALES------------------------------------------------
extern int columnas,filas;
extern unsigned long int k;
extern bool pruebas;

//----PEDIMOS LAS DIMENSIONES AL USUARIO--------------------------------
int Pedir(int argc, char **argv){
// Se comprueba numero de argumentos pasados en la llamada al programa.
    switch (argc) {
        case 1: 
            printf("Introduzca dimensiones\n Filas: ");
            scanf("%d", &filas);
            printf(" Columnas: ");
            scanf("%d", &columnas);
            break;
        case 2:
            printf("Número de argumentos erroneo.\n");
            exit(1);
        case 3:
            filas = atoi(argv[1]);    // Conversión de tipo char a int.
            columnas = atoi(argv[2]); // mediante función "atoi", de la
            break;                    // librería <cstdlib>.
        case 4:
            filas = atoi(argv[1]);
            columnas = atoi(argv[2]);
            pruebas = true;
            break;
    }

    // Se ajustan las dimensiones para que sean impares siempre.
    (filas%2) ? filas : filas+=1;
    (columnas%2) ? columnas : columnas+=1;
    return 0;
}

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
    // Se establecen la entrada y la salida del laberinto.
    grid[0][1] = ' '; 
    grid[filas-1][columnas-2] = ' ';
    
    return 0;
}

//----MUESTRA EN CONSOLA EL LABERINTO O LOS DATOS DE EJECUCIÓN-----------
void PrintGrid(char **grid, double tiempo){

    if (!pruebas){ // Se comprueba si se está ejecutando una prueba o no.
        printf("\n");
        for (int i=0; i<filas; i++) {
            for (int j=0; j<columnas; j++)
                printf("%c",grid[i][j]);
            printf("\n");
        }
        printf("\nFilas: %d, Columnas: %d, Area: %d", 
            filas, columnas, filas*columnas);
        printf("\nTiempo en generar: %2.4fs, ", tiempo);
        printf("Iteraciones: %ld\n", k);
        printf("\n");
    } else{
        printf("%d ", filas);
        printf("%d ", filas*columnas);
        printf("%2.4f ", tiempo);
        printf("%ld\n", k);
    }
}

//----COMPRUEBA SI LA CASILLA A VISITAR ESTÁ DENTRO DE LOS LÍMITES-------
int IsInBounds(int x, int y){
    if (x < 1 || x > (filas-2)) return false;
    if (y < 1 || y > (columnas-2)) return false;
    return true;
}

//----LIBERA TODA LA MEMORIA RESERVADA------------------------------------
void Free(char **grid){
    //Se libera la memoria para cada vector fila.
    for (int i = 0; i < filas; ++i)
        free(grid[i]);
    //Se libera memoria para el vector de vectores fila.
    free(grid);
}