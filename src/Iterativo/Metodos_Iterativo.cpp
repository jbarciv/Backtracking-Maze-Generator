///======================================================================
// Metodos_Iterativo.cpp
//
// Funciones llamadas en main y en Visit
//
//======================================================================
#include "Maze_Iterativo.hpp"

//----VARIABLES GLOBALES------------------------------------------------
extern int columnas,filas;
extern unsigned long int k;
extern bool pruebas;

//----PEDIMOS LAS DIMENSIONES AL USUARIO--------------------------------
int Pedir(int argc, char **argv){
// Se comprueba numero de argumentos pasados en la llamada al programa.
    switch (argc) {
        case 1: 
            printf("Introduzca dimensiones\n Filas: ");
            scanf("%d", &filas);
            printf(" Columnas: ");
            scanf("%d", &columnas);
            break;
        case 2:
            printf("Número de argumentos erroneo.\n");
            exit(1);
        case 3:
            filas = atoi(argv[1]);    // Conversión de tipo char a int.
            columnas = atoi(argv[2]); // mediante función "atoi", de la
            break;                    // librería <cstdlib>.
        case 4:
            filas = atoi(argv[1]);
            columnas = atoi(argv[2]);
            pruebas = true;
            break;
    }

    // Se ajustan las dimensiones para que sean impares siempre.
    (filas%2)?filas:filas+=1;
    (columnas%2)?columnas:columnas+=1;
    return 0;
}



//----FUNCIONES DE LA PILA----------------------------------------------
// Para agregar elementos a la pila.
void AgregarPila(Nodo *&pila, int pos_x, int pos_y,int i, bool estate,
                 short int dir[]){
    // Se reserva memoria para el nuevo nodo.
    Nodo *nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
    // Se asignan los campos recibidos por la función al nuevo nodo.
    nuevo_nodo -> x = pos_x; 
    nuevo_nodo -> y = pos_y;
    nuevo_nodo -> iter = i;
    nuevo_nodo -> estado = estate;
    for(int j=0; j<4; j++) nuevo_nodo -> v[j] = dir[j];
    // Se establece el nuevo nodo como el primero.
    nuevo_nodo -> siguiente = pila;
    pila = nuevo_nodo;
}
// Para sacar elementos a la pila.
void SacarPila(Nodo *&pila,int *pos_x, int *pos_y){
    // Se crea un nodo auxiliar y se guardan datos del nodo a eliminar.
    Nodo *aux = pila;
    *pos_x = aux -> x;
    *pos_y = aux -> y;
    // Se establece el anterior nodo como el primero y se libera memoria.
    pila = aux -> siguiente;
    free (aux);  
}

//----COMPRUEBA SI LA CASILLA A VISITAR ESTÁ DENTRO DE LOS LÍMITES-------
int IsInBounds(int x, int y){
    if (x < 1 || x > (filas-2)) return false;
    if (y < 1 || y > (columnas-2)) return false;
    return true;
}

