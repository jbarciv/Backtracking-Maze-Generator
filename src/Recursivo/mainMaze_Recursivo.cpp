//======================================================================
// Maze_Recursivo.cpp
// 
// Basado en el algoritmo de Abe Pralle  maze.cpp 
//  - Creación del algoritmo   2006.03.30
//  - Convertido a C++         2010.04.02
// 
// --> Implementación de un generador dinámico de laberintos en C++ <--
//
// Historia:
// 2021.04.15
// Celia Ramos, Josep María Barberá, Gonzalo Quirós - Implementación
// 2021.04.18
// Celia Ramos, Josep María Barberá - Primera versión 
// 2021.04.23
// Gonzalo Quirós - Versión final
//
//======================================================================


#include "Maze_Recursivo.hpp"

//----VARIABLES GLOBALES------------------------------------------------
int columnas,filas;
unsigned long int k=0;

int main(){

  int i;
  // Se pide al usuario el tamaño del laberinto.
  Pedir();
  // Se ajustan las dimensiones para que sean impares.
  Arreglar_2D();
    
  char **grid = NULL;
  // Se reserva memoria dinámica (del tamaño de "filas").
  grid = (char **) malloc (filas * sizeof(char *)); 
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

  // Rellenamos la matriz (de '#')
  SetGrid(grid);

  // Empieza la recursión. Se comienza visitando la posición (1,1).
  Visit(1,1,grid); 
  
  // Mostramos por pantalla el laberinto
  PrintGrid(grid);
  
  // Se libera memoria para cada fila.
  for (i = 0; i < filas; ++i)
    free(grid[i]);

  //Se libera memoria para el vector de vectores.
  free(grid);

  printf("%d,", columnas);
  printf("%d,", filas);
  printf("%ld\n", k); // Muestra en consola el nº de iteraciones.

  return 0;
}