//======================================================================
// mainMaze_Iterativo.cpp
//
// C implementation of an iterative maze generation program
//
// History:
// 2021.04.19
// Celia Ramos, Josep Maria Barberá, Gonzalo Quiros - created
// 2021.04.21
// Celia Ramos, Josep Maria Barberá, Gonzalo Quiros - First version
// 2021.04.22
// Josep Maria Barberá - Pile implementation
// 2021.04.23 - Final version
//======================================================================


#include "Maze_Iterativo.hpp"


//----VARIABLES GLOBALES------------------------------------------------
int columnas,filas, vect[4]={0,0,0,0};
long int k=0;

int main(){
    int i=0;
    
   // Se pide al usuario el tamaño del laberinto.
    printf("Introduzca dimensiones\n Filas: ");
    scanf("%d", &filas);
    printf(" Columnas: ");
    scanf("%d", &columnas);
    
    Arreglar_2D();
    
    char **grid = NULL;
    
    srand(time(0));
    SetGrid(grid);
    Nodo *pila = NULL;
    agregarPila(pila,1,1,0,false,vect);
    Visit(1,1,grid,pila); // Función recursiva.
    PrintGrid(grid);
    
    // Se libera memoria para cada fila.
    for (i = 0; i < filas; ++i) {
    	free(grid[i]);
    }
  	free(grid); //Se libera memoria para el vector de vectores ("primera columna").
    return 0;
}