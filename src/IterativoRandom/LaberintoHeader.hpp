#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ARRIBA 0
#define DERECHA 1
#define ABAJO 2
#define IZQUIERDA 3

#define ADELANTE true
#define ATRAS false

#define MURO '#'
#define PASILLO  ' ' 

bool comprobacion (unsigned int*, unsigned int*, char**);
bool esPosible (unsigned int*, unsigned int*, char**, int);
void SetGrid(char**, int, int);
void PrintGrid(char **, int, int);
void MakeMaze (char **);
bool isOnBounds(unsigned int, unsigned int);
bool cambioCasilla (unsigned int*, unsigned int*, int, bool);



// funciones celia:
bool inbounds(int, int);
void recorre (char**, int, int);
int cuantosrodean(char**, int, int);
bool valida(int, int, char**);