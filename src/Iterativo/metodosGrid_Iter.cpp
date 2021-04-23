//======================================================================
// metodosGrid_Iter.cpp
//
// General methods for grid implementation
//
//======================================================================

#include "Maze_Iterativo.hpp"

//----VARIABLES GLOBALES------------------------------------------------
extern int columnas,filas;
extern long int k;

//----PEDIMOS LAS DIMENSIONES AL USUARIO--------------------------------
void pedir(){
    // Se pide al usuario el tamaño del laberinto.

    printf("Introduzca dimensiones\n Filas: ");
    scanf("%d", &filas);
    
    printf(" Columnas: ");
    scanf("%d", &columnas);
}

//----FUNCIONES PARA CONSTRUIR LA GRID----------------------------------
void Arreglar_2D(){
    (filas%2)?filas:filas+=1;
    (columnas%2)?columnas:columnas+=1;
}

void SetGrid(char **grid){
    int i,j;

    for (i=0; i<filas; ++i){
        for(j=0; j<columnas; ++j)
            grid[i][j]='#';
    }
}

void PrintGrid(char **grid){
 // Muestra el laberinto final en la consola.
    for (int i=0; i<filas; i++) {
        for (int j=0; j<columnas; j++)

            // Si la consola admite unicode, recomendamos descomentar el
            // siguiente bloque de codigo

            /*
            if (grid[i][j]=='#'){
                cout << "\u2B1C";
            }
            else {
                cout << "  ";
            }
            */

            // En caso de descomentar el bloque anterior, 
            // comentar la siguiente linea

            printf("%c",grid[i][j]);
            
        printf("\n");
    }
    printf("num. de iteraciones= %ld", k);
    // printf("filas= %d, columnas=%d", filas, columnas);
}