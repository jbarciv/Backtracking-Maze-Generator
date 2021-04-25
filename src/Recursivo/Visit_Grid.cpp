//======================================================================
// Maze_Recursivo.cpp 
//
// Visit function to walk along the grid
//
//======================================================================

#include "Maze_Recursivo.hpp"

//----VARIABLES GLOBALES------------------------------------------------
extern unsigned long int k;

//----FUNCIONES RECURSIVA: VISIT------------------------------------
void Visit(int x, int y, char **grid){
    
    k++; // Contador de iteraciones (número de llamadas a Visit).
    // Primero borrar lo que haya en la casilla visitada.
    grid[x][y]= ' '; 
    // Crea un vector local en las 4 direcciones y lo desordena aleatoriamente
    int dirs[4] = {ARRIBA, DERECHA, ABAJO, IZQUIERDA};
    for (int i=0; i<4 ; ++i){
        int r = rand() % 4;   // Se elige una componente al azar.
        int temp = dirs[r]; 
        dirs[r] = dirs[i];    // Se intercambia por la componente i-ésima.
        dirs[i] = temp;
    }
    // Recorre por orden cada dirección (aleatorizada) e intenta visitarla.
    for (int i=0; i<4; ++i){
        // dx, dy son las direcciones según filas y columnas respectivamente,
        // en las que se desea realizar el siguiente movimiento.
        int dx=0, dy=0;
        switch (dirs[i]){
            case ARRIBA: dx = -1; break;
            case ABAJO: dx = 1; break;
            case DERECHA: dy = 1; break;
            case IZQUIERDA: dy = -1; break;
        }
        // Se obtiene la posición (x2,y2) dos casillas más adelante 
        // según la dirección que marcan dx, dy.
        int x2 = x + (dx*2);
        int y2 = y + (dy*2);
        // Se comprueba si la casilla a visitar está dentro del límite.
        if (IsInBounds(x2,y2)){
            // Se comprueba además que no se haya visitado antes.
            if (grid[x2][y2] == '#'){
                // Se quita la "pared entre la posición actual y la nueva.
                grid[x2-dx][y2-dy] = ' ';
                Visit(x2,y2,grid); // Recursively Visit (x2,y2)
            }
        }
    }
}
