//======================================================================
// Visit_Iterativo.cpp 
//
// Función Visit para recorrer/construir el laberinto de forma ITERATIVA
//
//======================================================================

#include "Maze_Iterativo.hpp"

//----VARIABLES GLOBALES------------------------------------------------
extern int vect[4];
extern long int k;

//----FUNCIONES ITERATIVA: VISIT----------------------------------------
int Visit(int x, int y, char **grid, Nodo *pila){
    int i=0;
    while(pila != NULL){
        if(pila->estado){
            if(pila->iter < 3){
                ;
            }
            else if(pila != NULL){
                SacarPila(pila,&x,&y);
                continue;
            }
        }else{  
            grid[x][y] = ' ';
            // Crea un vector local con las 4 direcciones 
            //y cambia aleatoriamente su orden.
            int dirs[4] = {ARRIBA, DERECHA, ABAJO, IZQUIERDA};

            for (int i=0; i<4; ++i){
                int r = rand()%4;   // Se elige una componente al azar.
                int temp = dirs[r]; 
                dirs[r] = dirs[i];  // Se intercambia por la componente i-ésima.
                dirs[i] = temp;
            }
            pila->estado = true;
            for(i=0;i<4;i++) pila->v[i]=dirs[i];
        }
        // Recorre cada dirección e intenta visitarla.
        for (i=pila->iter; i<4; ++i){
            // dx,dy are offsets from current location. Set them based
            // on the next direction I wish to try.
            int dx=0, dy=0;
            switch (pila->v[i]){
                case ARRIBA: dx = -1; break;
                case ABAJO: dx = 1; break;
                case DERECHA: dy = 1; break;
                case IZQUIERDA: dy = -1; break;
            }
            // Find the (x,y) coordinates of the grid cell 2 spots
            // away in the given direction.
            int x2 = x + (dx*2);
            int y2 = y + (dy*2);
            // printf("antes(%u,%u)\n",x,y);
            if (IsInBounds(x2,y2)){
                if (grid[x2][y2] == '#'){
                    // (x2,y2) has not been visited yet... knock down the
                    // wall between my current position and that position
                    grid[x2-dx][y2-dy] = ' ';
                    x=x2;
                    y=y2;
                    pila->iter = i;
                    AgregarPila(pila,x,y,i=0,false,vect);
                    break;
                }
            }
        }
        pila->iter = i;
        k++;
    }
    return k;
}   