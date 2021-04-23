//======================================================================
// mainMaze_Recursivo.cpp
// 
// Based on Abe Pralle maze.cpp algorithm created on 2006.03.30
// 
// C implemntation of maze make recursive algorithm
//
// History:
// 2021.04.15
// Celia Ramos, Josep Maria Barberá, Gonzalo Quirós - created
// 2021.04.18
// Celia Ramos, Josep Maria Barberá - First version
// 2021.04.23
// Gonzalo Quirós - Final version
//
//======================================================================


#include "Maze_Recursivo.hpp"

//----VARIABLES GLOBALES------------------------------------------------
int columnas,filas;
double k=0;

int main(){
   int i;
    // Se pide al usuario el tamaño del laberinto.
    pedir();

    Arreglar_2D();
    
    char **grid = NULL;
    // Se reserva memoria para el vector de vectores dinámicos (del tamaño de "filas").
  	grid = (char **) malloc (filas * sizeof(char *)); 
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
    
    // Hacemos la matriz
    SetGrid(grid);

    // Empieza la recursion
    Visit(1,1,grid); 
    
    // Mostramos por pantalla
    PrintGrid(grid);

    printf("Nº iteraciones= %f\n", k);
    
    // Se libera memoria para cada fila.
    for (i = 0; i < filas; ++i) {
    	free(grid[i]);
    }

    //Se libera memoria para el vector de vectores ("primera columna")
  	free(grid);

    printf("todo perfecto!\n");
    
    return 0;
}