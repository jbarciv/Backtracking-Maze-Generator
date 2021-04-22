#include "EncabezadoPruebas.hpp"

unsigned int nfilas;
unsigned int ncol;

int main(){
    int i;


    printf("Iterativo \n");

    // Se pide al usuario el tamaño del laberinto.
    printf("Introduzca dimensiones\n Filas: ");
    scanf("%d", &nfilas);
    printf(" Columnas: ");
    scanf("%d", &ncol); 

    ncol+=2;   // (chema): creo que no tiene por qué hacerse...
    nfilas+=2; // Añadimos un marco que serán los bordes del laberinto

    char **grid = NULL;
    // Se reserva memoria para el vector de vectores dinámicos (del tamaño de "filas").
    grid = (char **) malloc (nfilas  * sizeof(char *)); 
    if (grid == NULL) {
        printf("No se pudo reservar memoria\n");
        return -1;
    }
    // Se reserva memoria para cada fila (del tamaño de "columnas").
    for (i = 0; i < nfilas; ++i) {
        grid[i] = (char *) malloc (ncol * sizeof(char));
        if (grid[i] == NULL) {
            printf("No se pudo reservar memoria\n");
            return -1;
        }
    }

    srand(time(0)); // Generador de numero aleatorio.
    printf("he llegado hasta Srand\n");
    SetGrid(grid, nfilas, ncol);
    printf("he hecho la grid\n");
    MakeMaze(grid);
    printf("he hecho el laberinto\n"); 
    PrintGrid(grid,nfilas,ncol);

    // Se libera memoria para cada fila.
    for (i = 0; i < nfilas; ++i) {
        free(grid[i]);
    }
    free(grid); //Se libera memoria para el vector de vectores ("primera columna").

    return 0;
}