//======================================================================
// Metodos_Grid.cpp
//
// Métodos generales para la implementación correcta de la matriz
//
//======================================================================

#include "Maze_Recursivo.hpp"

//----VARIABLES GLOBALES------------------------------------------------
extern int columnas,filas;

//----PEDIMOS LAS DIMENSIONES AL USUARIO--------------------------------
void Pedir(){
    printf("Introduzca dimensiones\n Filas: ");
    scanf("%d", &filas);
    printf(" Columnas: ");
    scanf("%d", &columnas);
}

//----INICIALIZAMOS LA MATRIZ RELLENANDO CON'#'--------------------------
void SetGrid(char **grid){
    int i,j;
    for (i=0; i<filas; ++i){
        for(j=0; j<columnas; ++j)
            grid[i][j]='#';
    }
}

//----COMPRUEBA SI LA CASILLA A VISITAR ESTÁ DENTRO DE LOS LÍMITES-------
int IsInBounds(int x, int y){
 if (x < 1 || x > (filas-2)) return false;
 if (y < 1 || y > (columnas-2)) return false;
 return true;
}

//----MUESTRA EN CONSOLA EL LABERINTO------------------------------------
void PrintGrid(char **grid){
    for (int i=0; i<filas; i++) {
        for (int j=0; j<columnas; j++)
            printf("%c",grid[i][j]);
        printf("\n");
    }
}