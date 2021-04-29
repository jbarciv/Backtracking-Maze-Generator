//======================================================================
// Maze_Recursivo.hpp
//
// Librerías, directivas del preprocesador y prototipos de funciones 
// para Maze_Recursivo.cpp, Metodos_Grid.cpp y Visit_Recursivo.cpp
//
//======================================================================

#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

//----CONSTANTES--------------------------------------------------------
#define ARRIBA 0
#define DERECHA 1
#define ABAJO 2
#define IZQUIERDA 3

//----PROTOTIPOS DE FUNCIONES-------------------------------------------
int Pedir(int ,char **);
int SetGrid(char **);
void PrintGrid(char **,int ,char **, double);
int IsInBounds( int , int );
void Free(char **);
void Visit(int , int , char **);