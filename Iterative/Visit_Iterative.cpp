//======================================================================
// Visit_Iterativo.cpp 
//
// Función Visit para recorrer/construir el laberinto de forma ITERATIVA
//
//======================================================================

#include "Maze_Iterative.hpp"

//----VARIABLES GLOBALES------------------------------------------------
extern long int k;

//----FUNCIÓN ITERATIVA: VISIT----------------------------------------
int Visit(int x, int y, char **grid, Nodo *pila){
    short int i=0;
    short int vect[4]={0,0,0,0};
    // Mientras la pila no esté vacía continua la iteración.
    while(pila){
        // Comprueba si ya ha estado en la casilla.
        if( pila->estado ){      
            if(pila->iter < 4); // Si le falta alguna iteración la intenta.
            else{               // En otro caso "retrocede" al nodo anterior.
                SacarPila(pila, &x, &y);
                continue;       
            }
        } else{
            // Si no ha estado borra lo que haya en la casilla visitada.
            grid[x][y] = ' ';
            // Crea un vector local en las 4 direcciones y 
            // cambia aleatoriamente su orden.
            short int dirs[4] = {ARRIBA, DERECHA, ABAJO, IZQUIERDA};
            for (i=0; i<4; ++i){
                short int r = rand()%4;   // Se elige una componente al azar.
                short int temp = dirs[r]; 
                dirs[r] = dirs[i];        // Se intercambia por la i-ésima.
                dirs[i] = temp;
            }
            // Establece que ya ha visitado la casilla y guarda "dirs".
            pila->estado = true;          
            for(i=0;i<4;i++) pila->v[i]=dirs[i];
        }
        // Recorre por orden cada dirección (aleatorizada) e intenta visitarla.
        for (i=pila->iter; i<4; ++i){
            // dx, dy son direcciones según filas y columnas respectivamente,
            // en las que se desea realizar el siguiente movimiento.
            short int dx=0, dy=0;
            switch (pila->v[i]){
                case ARRIBA: dx = -1; break;
                case ABAJO: dx = 1; break;
                case DERECHA: dy = 1; break;
                case IZQUIERDA: dy = -1; break;
            }
            // Se obtiene la posición (x2,y2) dos casillas más adelante, 
            // según la dirección que marcan dx, dy.
            int x2 = x + (dx*2);
            int y2 = y + (dy*2);
            // Se comprueba si la casilla a visitar está dentro del límite.
            if (IsInBounds(x2,y2)){
                // Se comprueba además que no se haya visitado antes.
                if (grid[x2][y2] == '#'){
                    // Se quita la "pared" entre la posición actual y la nueva.
                    grid[x2-dx][y2-dy] = ' ';
                    // Se establece la nueva casilla a visitar.
                    x=x2;
                    y=y2;
                    // Se guarda la iteración.
                    pila->iter = i;
                    // Se añade el nuevo nodo de la casilla a visitar.
                    AgregarPila(pila,x,y,i=0,false,vect);
                    break;
                }
            }
            // En caso de haber intentado los cuatro movimientos
            // y no haber podido guarda la iteración.
            if(i == 3) pila->iter = ++i;
        }
        k++;
    }
    return k;
}   