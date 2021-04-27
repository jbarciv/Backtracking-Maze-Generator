//======================================================================
// Maze_Iterativo.hpp
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

//----DEFINICIÓN DE TIPOS ----------------------------------------------
struct Nodo{
    int x;
    int y;
    int iter;
    bool estado;
    int v[4];
    Nodo *siguiente;
};

//----PROTOTIPOS DE FUNCIONES ITERATIVAS--------------------------------
int Pedir(int ,char **);
int SetGrid(char **);
void AgregarPila(struct Nodo *&, int,  int, int, bool, int *);
void SacarPila(struct Nodo *&, int *, int *);
int IsInBounds( int , int );
int Visit(int , int , char **,struct Nodo *);
void PrintGrid(char **,int ,char **);
void Free(char **);