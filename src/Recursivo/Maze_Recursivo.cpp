//======================================================================
// Maze_Recursivo.cpp 
//
// Visit function to walk along the grid
//
//======================================================================


#include "Maze_Recursivo.hpp"
//----VARIABLES GLOBALES------------------------------------------------
extern int columnas,filas;
extern double k;

//----FUNCIONES QUE RECORREN LA GRID------------------------------------
int IsInBounds(int x, int y){
 // Devuelve "true" si x2 e y2 estan dentro de los límites.
 if (x < 1 || x > (filas-2)) return false;
 if (y < 1 || y > (columnas-2)) return false;
 return true;
}

int Visit(int x, int y, char **grid){
    // Comenzando en la casilla dada, visita recursivamente cada
    // direccion en orden aleatorio

    // Se establece la primera ubicación como vacía.
    
    k++;
    grid[x][y]= ' ';
    // Crea un vector local con las 4 direcciones y cambia aleatoriamente su orden.
    int dirs[4] = {ARRIBA, DERECHA, ABAJO, IZQUIERDA};

    for (int i=0; i<4; ++i){
        int r = rand()%4;   // Se elige una componente al azar.
        int temp = dirs[r]; 
        dirs[r] = dirs[i];  // Se intercambia por la componente i-ésima.
        dirs[i] = temp;
    }
    // Recorre cada dirección e intenta visitarla.
    for (int i=0; i<4; ++i){
        // dx,dy are offsets from current location. Set them based
        // on the next direction I wish to try.
        int dx=0, dy=0;
        switch (dirs[i]){
            case ARRIBA: dx = -1; break;
            case ABAJO: dx = 1; break;
            case DERECHA: dy = 1; break;
            case IZQUIERDA: dy = -1; break;
        }
        // Find the (x,y) coordinates of the grid cell 2 spots
        // away in the given direction.
        int x2 = x + (dx*2);
        int y2 = y + (dy*2);
        // printf("antes(%u,%u)\n",x,y); //quizás queda más elegante dy<<1 que es lo mismo
        if (IsInBounds(x2,y2)){
            if (grid[x2][y2] == '#'){
                // (x2,y2) has not been visited yet... knock down the
                // wall between my current position and that position
                grid[x2-dx][y2-dy] = ' ';
                // Recursively Visit (x2,y2)
                Visit(x2,y2,grid);
            }
        }
    }
    return k;
}