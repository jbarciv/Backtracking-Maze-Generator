#include "laberinto.hpp"

int main(){
   unsigned int i;
   int filas=0;
   int columnas=0;

   // Se pide al usuario el tamaño del laberinto.
    printf("Introduzca dimensiones\n Filas: ");
    scanf("%u", &filas);
    printf(" Columnas: ");
    scanf("%u", &columnas);

    columnas+=2;   
    filas+=2; // Añadimos un marco que serán los bordes del laberinto
    
    char **grid = NULL;
    // Se reserva memoria para el vector de vectores dinámicos (del tamaño de "filas").
  	grid = (char **) malloc (filas  * sizeof(char *)); 
	if (grid == NULL) {
  		printf("No se pudo reservar memoria\n");
		return -1;
  	}
    // Se reserva memoria para cada fila (del tamaño de "columnas").
  	for (i = 0; i < filas; ++i) {
    	grid[i] = (char *) malloc (columnas * sizeof(char));
    	if (grid[i] == NULL) {
  			printf("No se pudo reservar memoria\n");
			return -1;
  		}
  	}
    
    srand(time(0)); // Generador de numero aleatorio.

    SetGrid(grid, filas, columnas);
    MakeMaze(grid);
    PrintGrid(grid,filas,columnas);
    
    // Se libera memoria para cada fila.
    for (i = 0; i < filas; ++i) {
    	free(grid[i]);
    }
  	free(grid); //Se libera memoria para el vector de vectores ("primera columna").

    return 0;
}

