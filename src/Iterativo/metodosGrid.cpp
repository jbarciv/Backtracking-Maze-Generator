//----------------------------------------------------------------------
// Maze_Iterativo.cpp
//
// General methods for a grid implementation
//
//----------------------------------------------------------------------

#include "Maze_Iterativo.hpp"

//----VARIABLES GLOBALES------------------------------------------------
extern int columnas,filas;
extern long int k=0;



void SetGrid(char **grid){
    int i,j;

    // Se reserva memoria para el vector de vectores dinámicos (del tamaño de "filas").
    grid = (char **) malloc (filas * sizeof(char *)); 
    if (grid == NULL) {
        printf("No se pudo reservar memoria\n");
    }
    // Se reserva memoria para cada fila (del tamaño de "columnas").
    for (i = 0; i < filas; ++i) {
        grid[i] = (char *) malloc (columnas * sizeof(char));
        if (grid[i] == NULL) {
            printf("No se pudo reservar memoria\n");
        }
    }

    for (i=0; i<filas; ++i){
        for(j=0; j<columnas; ++j)
            grid[i][j]='#';
    }
}

void PrintGrid(char **grid){
 // Muestra el laberinto final en la consola.
    for (int i=0; i<filas; i++) {
        for (int j=0; j<columnas; j++)
            //Si la consola admite unicode, recomendamos descomentar el
            //siguiente bloque de codigo
            /*
            if (grid[i][j]=='#'){
                cout << "\u2B1C";
            }
            else {
                cout << "  ";
            }
            */
           //En caso de descomentar el bloque anterior, comentar la siguiente linea
            printf("%c",grid[i][j]);
        printf("\n");
    }
    printf("nº de iteraciones= %ld", k);
    // printf("filas= %d, columnas=%d", filas, columnas);
}