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


#include "pruebas_Maze_Recursivo.hpp"

//----VARIABLES GLOBALES------------------------------------------------
int columnas,filas;
unsigned long int k=0;

//----FUNCIÓN PRINCIPAL-------------------------------------------------
int main(){
  char **grid = NULL;
  srand(time(0));     // Semilla aleatoria para la función rand().

  // Se pide al usuario el tamaño del laberinto.
  Pedir();

  // Rellenamos la matriz (de '#')
  grid = SetGrid(grid);

  // Empieza la recursión. Se comienza visitando la posición (1,1).
  Visit(1,1,grid); 
  
  // Mostramos por pantalla el laberinto
  // PrintGrid(grid);
  printf("%d ", columnas);
  printf("%d ", filas);
  printf("%ld\n", k); // Muestra el nº de iteraciones.

  // Se libera memoria.
  Free(grid);
   
  return 0;
}