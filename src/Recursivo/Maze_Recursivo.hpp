//======================================================================
// Maze_Recursivo.hpp
//
// Libraries, preprocessor directives and methods prototypes for 
// mainMaze_Iterativo.cpp, metodosGrid.cpp and Maze_Iterativo.cpp
//
//======================================================================


#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
//----CONSTANTES--------------------------------------------------------
#define ARRIBA 0
#define DERECHA 1
#define ABAJO 2
#define IZQUIERDA 3

//----PROTOTIPOS DE FUNCIONES-------------------------------------------
void pedir();
void Arreglar_2D();
void SetGrid(char **);
int IsInBounds( int , int );
int Visit(int , int , char **);
void PrintGrid(char **);