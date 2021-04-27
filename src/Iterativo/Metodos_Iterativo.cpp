///======================================================================
// Metodos_Iterativo.cpp
//
// Funciones llamadas en main y en Visit
//
//======================================================================
#include "Maze_Iterativo.hpp"

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
            filas = atoi(argv[1]);
            columnas = atoi(argv[2]);
            break;
        case 4:
            filas = atoi(argv[1]);
            columnas = atoi(argv[2]);
            pruebas = true;
            break;
    }

    // Se ajustan las dimensiones para que sean impares siempre.
    (filas%2)?filas:filas+=1;
    (columnas%2)?columnas:columnas+=1;
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
    // Se establece la entrada y la salida del laberinto.
    grid[0][1] = ' '; 
    grid[filas-1][columnas-2] = ' ';

    return 0;
}

//----FUNCIONES DE LA PILA----------------------------------------------
void AgregarPila(Nodo *&pila, int pos_x, int pos_y,int i, bool estate,
                 int dir[]){

    Nodo *nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));

    nuevo_nodo -> x = pos_x;
    nuevo_nodo -> y = pos_y;
    nuevo_nodo -> iter = i;
    nuevo_nodo -> estado = estate;

    for(int j=0; j<4; j++) nuevo_nodo -> v[j] = dir[j];

    nuevo_nodo -> siguiente = pila;
    pila = nuevo_nodo;
}

void SacarPila(Nodo *&pila,int *pos_x, int *pos_y){
    Nodo *aux = pila;
    *pos_x = aux -> x;
    *pos_y = aux -> y;
    pila = aux -> siguiente;
    free (aux);  
}

//----COMPRUEBA SI LA CASILLA A VISITAR ESTÁ DENTRO DE LOS LÍMITES-------
int IsInBounds(int x, int y){
    if (x < 1 || x > (filas-2)) return false;
    if (y < 1 || y > (columnas-2)) return false;
    return true;
}

//----MUESTRA EN CONSOLA EL LABERINTO O LOS DATOS DE EJECUCIÓN-----------
void PrintGrid(char **grid,int argc, char **argv){
    if (!pruebas){ // se comprueba si se está ejecutando una prueba o no.
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