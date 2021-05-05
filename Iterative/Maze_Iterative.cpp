//======================================================================
// Maze_Iterativo.cpp
//
// --> Implementación de un generador dinámico de laberintos <--
//           en C++ mediante un algoritmo ITERATIVO 
//
// Historia:
// 2021.04.19
// Celia Ramos, Josep Maria Barberá, Gonzalo Quirós - Creación
// 2021.04.21
// Celia Ramos, Josep Maria Barberá, Gonzalo Quirós - Primera versión
// 2021.04.22
// Josep Maria Barberá - Implementación mediante pila
// 2021.04.23 - Versión final
//======================================================================

#include "Maze_Iterative.hpp"

//----VARIABLES GLOBALES------------------------------------------------
int columnas,filas;
unsigned long int k=0;
bool pruebas = false;

int main(int argc, char **argv){
    short int vect[4]={0,0,0,0};
    char **grid = NULL;
    unsigned int t0, t1;
    double tiempo;
    // Semilla aleatoria para la función rand().
    srand(time(0));    

    // Se pide al usuario el tamaño del laberinto.
    Pedir(argc,argv);
    
    // Se crea la matriz y se inicializa (llena de '#').
    grid = (char **) malloc (filas * sizeof(char *)); 
    SetGrid(grid);

    // Se crea la pila y se agrega el primer nodo.
    Nodo *pila = NULL;
    AgregarPila(pila, 1, 1, 0, false, vect);
    
    // Empieza la iteracion. Se comienza visitando la posición (1,1).
    // Se toma además el tiempo al entrar y salir de la función, en ticks.
    t0=clock();
    Visit(1, 1, grid, pila);
    t1=clock(); 
    
    // Se pasa de ticks a segundos.
    tiempo = (double(t1-t0)/CLOCKS_PER_SEC); 

    // Mostramos por pantalla el laberinto
    PrintGrid(grid, tiempo);

    // Se libera memoria.
    Free(grid);

    return 0;
}