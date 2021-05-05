///======================================================================
// Stack_Methods.cpp
//
// Funciones llamadas en main y en Visit
//
//======================================================================

#include "Maze_Iterative.hpp"

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
