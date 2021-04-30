//======================================================================
// Maze_Recursivo.cpp
// 
// Basado en el algoritmo de Abe Pralle  maze.cpp 
//  - Creación del algoritmo   2006.03.30
//  - Convertido a C++         2010.04.02
// 
// --> Implementación de un generador dinámico de laberintos <--
//           en C++ mediante un algoritmo RECURSIVO 
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
  unsigned int t0, t1;
  double tiempo;
  // Semilla aleatoria para la función rand().
  srand(time(0));    

  // Se pide al usuario el tamaño del laberinto.
  Pedir(argc, argv);

  // Se crea la matriz y se inicializa (llena de '#')
  grid = (char **) malloc (filas * sizeof(char *)); 
  SetGrid(grid);

  
  // Empieza la recursión. Se comienza visitando la posición (1,1).
  // Se toma además el tiempo al entrar y salir de la función, en ticks.
  t0 = clock();
  Visit(1, 1, grid); 
  t1=clock();
  
  // Se pasa de ticks a segundos.
  tiempo = (double(t1-t0)/CLOCKS_PER_SEC); 

  // Mostramos por pantalla el laberinto
  PrintGrid(grid, tiempo);

  // Se libera memoria.
  Free(grid);
   
  return 0;
}