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

//----PROTOTIPOS DE FUNCIONES ITERATIVAS--------------------------------
void Arreglar_2D();
void SetGrid(char **);
void agregarPila(struct Nodo *&, int,  int, int, bool, int *);
void sacarPila(struct Nodo *&, int *, int *);
int IsInBounds( int , int );
int Visit(int , int , char **,struct Nodo *);
void PrintGrid(char **);