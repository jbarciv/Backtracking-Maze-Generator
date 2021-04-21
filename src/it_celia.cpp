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
    SetGrid(grid, filas, columnas);
    PrintGrid(grid, filas, columnas);

    for (i = 0; i < filas; ++i) {
    	free(grid[i]);
    }
  	free(grid);
    return 0;
}

// FUNCIONES:
void SetGrid(char ** grid, int filas, int columnas){
    unsigned i,j;
    for (i=0; i<filas; ++i){
        for(j=0; j<columnas; ++j)
            grid[i][j]='#';
    }
}

void PrintGrid(char **grid, int filas, int columnas){
 // Muestra el laberinto final en la consola. 
    for (int i=0; i<filas; ++i) { // de nuevo quito el unsigned
        for (int j=0; j<columnas; ++j)
            printf("%c",grid[i][j]);
        printf("\n");
    }
}

bool inbounds(int x, int y, char ** grid){
    if (x < 1 || x >= (filas-1)) return false;
    if (y < 1 || y >= (columnas-1)) return false;
    return true;
}

int cuantosrodean(int x, int y, char** grid){ //cuenta los # que rodean al punto (x,y)
    unsigned int up, down, left, right, i=0;
    up = x-1;
    down = x+1;
    left = y-1;
    right = y+1;
    if (grid[up][y] =='#') i++;
    if (grid[down][y] =='#') i++;
    if (grid[x][left] =='#') i++;
    if (grid[x][right] =='#') i++;
    return i;
}

bool valida (int x, int y, char** grid){
    if(grid[x][y] == ' ') return false;
    // por completar
}

void recorre (int x, int y, char ** grid){

    grid[x][y]=' ';

    int dirs[4];
    dirs[0] = ARRIBA;
    dirs[1] = DERECHA;
    dirs[2] = ABAJO;
    dirs[3] = IZQUIERDA;

    for (int i=0; i<4; ++i){
        int r = rand()%4;   // Se elige una componente al azar.
        int temp = dirs[r]; 
        dirs[r] = dirs[i];  // Se intercambia por la componente i-ésima.
        dirs[i] = temp;
    }
    // por completar
}