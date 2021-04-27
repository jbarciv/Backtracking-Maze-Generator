//======================================================================
// Maze_Iterativo.cpp
//
// --> Implementación de un generador dinámico de laberintos <--
//           en C++ mediante un algoritmo ITERATIVO 
//
// Historia:
// 2021.04.19
// Celia Ramos, Josep Maria Barberá, Gonzalo Quirós - Creación
// 2021.04.21
// Celia Ramos, Josep Maria Barberá, Gonzalo Quirós - Primera versión
// 2021.04.22
// Josep Maria Barberá - Implementación mediante pila
// 2021.04.23 - Versión final
//======================================================================


#include "Maze_Iterativo.hpp"


//----VARIABLES GLOBALES------------------------------------------------
int columnas,filas, vect[4]={0,0,0,0};
long int k=0;

int main(){
    int i=0;
    
    // Se pide al usuario el tamaño del laberinto.
    pedir();
    
    Arreglar_2D();
    
    char **grid = NULL;
    // Se reserva memoria para el vector de vectores dinámicos (del tamaño de "filas").
    grid = (char **) malloc (filas * sizeof(char *)); 
    if (grid == NULL) {
        printf("No se pudo reservar memoria\n");
    }
    // Se reserva memoria para cada fila (del tamaño de "columnas").
    for (i = 0; i < filas; ++i) {
        grid[i] = (char *) malloc (columnas * sizeof(char));
        if (grid[i] == NULL) {
            printf("No se pudo reservar memoria\n");
        }
    }
    
    srand(time(0));

    // Hacemos la matriz
    SetGrid(grid);

    // Hacemos la pila
    Nodo *pila = NULL;
    agregarPila(pila,1,1,0,false,vect);

    //Empieza la iteracion
    Visit(1,1,grid,pila);

    //Mostramos por pantalla
    PrintGrid(grid);
    
    // Se libera memoria para cada fila.
    for (i = 0; i < filas; ++i) {
    	free(grid[i]);
    }

  	//Se libera memoria para el vector de vectores ("primera columna")
    free(grid);

    return 0;
}