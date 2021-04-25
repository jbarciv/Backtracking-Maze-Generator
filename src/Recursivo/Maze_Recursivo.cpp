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

//----FUNCIÓN PRINCIPAL-------------------------------------------------
int main(){
  char **grid = NULL;

  // Se pide al usuario el tamaño del laberinto.
  Pedir();

  // Rellenamos la matriz (de '#')
  
  grid = SetGrid(grid);

  // Empieza la recursión. Se comienza visitando la posición (1,1).
  Visit(1,1,grid); 
  
  // Mostramos por pantalla el laberinto
  PrintGrid(grid);

  // Se libera memoria.
  Free(grid);
   
  return 0;
}