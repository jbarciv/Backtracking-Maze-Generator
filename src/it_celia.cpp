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
    recorre(1, 1, grid);
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
    for (int i=0; i<filas; ++i) {
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

int cuantosrodean(int x, int y, char** grid){ //cuenta los '#' que rodean al punto (x,y)
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

bool valida (int x, int y, int dirs, char** grid){ //comprueba si la casilla a la que vamos y la siguiente son validas

    if(grid[x][y] == ' ' || !inbounds(x,y, grid)) return false;

    if(!x || !y || x<sizeof(*grid) || y< sizeof(grid)){
    int dx, dy;
    switch (dirs){
        case ARRIBA: dx = -1; break;
        case ABAJO: dx = 1; break;
        case DERECHA: dy = 1; break;
        case IZQUIERDA: dy = -1; break;
        }
    
    int x2 = x + dx;
    int y2 = y + dy;

    if(grid[x2][y2] == ' ' ) return false;

    return true;
    }
}

void recorre (int x, int y, char ** grid){
    int n=0, j, x2, y2;
    
    int dirs[4];
    dirs[0] = ARRIBA;
    dirs[1] = DERECHA;
    dirs[2] = ABAJO;
    dirs[3] = IZQUIERDA;

    grid[x][y]=' ';
    
    do{
        for(j=0; j<4; j++){
            int r = rand()%4;
            int temp = dirs[r];
            dirs[r] = dirs[j];
            dirs[j] = temp;
        }

       for(j=0; j<4; j++) printf("%d,",dirs[j]);
       printf("\n");

        for (j=0; j<4; j++){
            switch (dirs[j]){
                case ARRIBA: x -= 1; break;
                case ABAJO: x += 1; break;
                case DERECHA: y += 1; break;
                case IZQUIERDA: y -= 1; break;
            }

            if(valida(x, y, dirs[j], grid)) {
                grid [x][y] = ' ';
                printf("\t %d",x);
                printf("\t %d",y);
                printf("\n %d casillas pintadas \n", ++n);
            }
        }
        
    }while (cuantosrodean(x,y,grid)==3 && inbounds(x,y, grid));
}
    
