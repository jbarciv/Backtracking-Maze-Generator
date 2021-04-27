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
bool pruebas = false;

//----FUNCIÓN PRINCIPAL-------------------------------------------------
int main(int argc, char **argv){
  char **grid = NULL;
  srand(time(0));    // Semilla aleatoria para la función rand().

  // Se pide al usuario el tamaño del laberinto.
  Pedir(argc,argv);

  // Rellenamos la matriz (de '#')
  grid = (char **) malloc (filas * sizeof(char *)); 
  SetGrid(grid);

  // Empieza la recursión. Se comienza visitando la posición (1,1).
  Visit(1,1,grid); 
  
  // Mostramos por pantalla el laberinto
  PrintGrid(grid,argc,argv);

  // Se libera memoria.
  Free(grid);
   
  return 0;
}