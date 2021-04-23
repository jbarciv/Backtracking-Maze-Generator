#include "Maze_Iterativo.hpp"



//----VARIABLES GLOBALES------------------------------------------------
extern int columnas,filas, vect[4]={0,0,0,0};
extern long int k=0;




//----FUNCIONES--------------------------------------------------------
void Arreglar_2D(){
    (filas%2)?filas:filas+=1;
    (columnas%2)?columnas:columnas+=1;
}



struct Nodo{
    int x;
    int y;
    int iter;
    bool estado;
    int v[4];
    Nodo *siguiente;
};

void agregarPila(Nodo *&pila, int pos_x, int pos_y, int i, bool estate, 
                int dir[]){

    Nodo *nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));

    nuevo_nodo -> x = pos_x;
    nuevo_nodo -> y = pos_y;
    nuevo_nodo -> iter = i;
    nuevo_nodo -> estado = estate;

    for(int j=0; j<4; j++) nuevo_nodo -> v[j]=dir[j];

    nuevo_nodo -> siguiente = pila;
    pila = nuevo_nodo;
}

void sacarPila(Nodo *&pila,int *pos_x, int *pos_y){
    Nodo *aux = pila;
    *pos_x = aux -> x;
    *pos_y = aux -> y;
    pila = aux -> siguiente;
    free (aux);  
}

int IsInBounds(int x, int y){
    // Devuelve "true" si x2 e y2 estan dentro de los límites.

    if (x < 1 || x > (filas-2)) return false;
    if (y < 1 || y > (columnas-2)) return false;

    return true;
}

int Visit(int x, int y, char **grid, Nodo *pila){
    int i=0;
    while(pila != NULL){
        if(pila->estado){
            if(pila->iter < 3){
                ;
            }
            else if(pila != NULL){
                sacarPila(pila,&x,&y);
                continue;
            }
        }else{  
            grid[x][y]=' ';
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
                    agregarPila(pila,x,y,i=0,false,vect);
                    break;
                }
            }
            if(i==3) pila->iter=4;
        }
        k++;
    }
    return k;
}   




