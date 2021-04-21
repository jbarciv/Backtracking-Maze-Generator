#include "laberinto.hpp"

// VBLES GLOBALES:
unsigned int columnas,filas;

//MAIN:
int main(){
    int i;  //contador

    printf("Introduzca dimensiones\n Filas: ");
    scanf("%u", &filas);
    printf(" Columnas: ");
    scanf("%u", &columnas);

    columnas+=2;   
    filas+=2;

    char ** grid = NULL;
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
    
    srand(time(0));
    SetGrid(filas, columnas, grid);

    for (i = 0; i < filas; ++i) {
    	free(grid[i]);
    }
  	free(grid);
    return 0;
}

// FUNCIONES:
void SetGrid(int filas, int columnas, char ** grid){
    unsigned i,j;
    for (i=0; i<filas; ++i){
        for(j=0; j<columnas; ++j)
            grid[i][j]='#';
    }
}

bool inbounds(int x, int y, char ** grid){
    if (x < 1 || x >= (filas-1)) return false;
    if (y < 1 || y >= (columnas-1)) return false;
    return true;
}

void