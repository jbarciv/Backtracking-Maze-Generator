//======================================================================
// Maze_Iterativo.hpp
//
// Librerías, directivas del preprocesador, prototipos de funciones y
// definición de tipos para Maze_Iterativo.cpp, Metodos_Grid.cpp, 
// Metodos_Pila.cpp y Visit_Iterativo.cpp
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

//----DEFINICIÓN DE TIPOS ----------------------------------------------
struct Nodo{
    int x;
    int y;
    int iter;
    bool estado;
    short int v[4];
    Nodo *siguiente;
};

//----PROTOTIPOS DE FUNCIONES ITERATIVAS--------------------------------
int Pedir(int ,char **);
int SetGrid(char **);
void AgregarPila(struct Nodo *&, int,  int, int, bool, short int *);
void SacarPila(struct Nodo *&, int *, int *);
int IsInBounds( int , int );
int Visit(int , int , char **,struct Nodo *);
void PrintGrid(char **,int ,char **, unsigned int, unsigned int);
void Free(char **);