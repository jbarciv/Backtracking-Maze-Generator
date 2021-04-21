#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//----CONSTANTES--------------------------------------------------------
#define ARRIBA 0
#define DERECHA 1
#define ABAJO 2
#define IZQUIERDA 3

//----VARIABLES GLOBALES------------------------------------------------
unsigned int columnas,filas;

//----PROTOTIPO DE FUNCIONES--------------------------------------------
void SetGrid(char **);
int IsInBounds( int , int );
void Visit(unsigned int , unsigned int , char **);
void PrintGrid(char **);

//----FUNCIONES--------------------------------------------------------
int main(){
   unsigned int i;
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

    SetGrid(grid);
    Visit(1, 1, grid); // Función recursiva.
    PrintGrid(grid);
    
    // Se libera memoria para cada fila.
    for (i = 0; i < filas; ++i) {
    	free(grid[i]);
    }
  	free(grid); //Se libera memoria para el vector de vectores ("primera columna").

    return 0;
}

void SetGrid(char **grid){
    // Rellenamos la malla con carácter '#'.
    unsigned int i,j;
    for (i=0; i<filas; ++i){
        for(j=0; j<columnas; ++j){
            if (!i && j==1) grid[i][j]=' '; //Casillas de entrada y salida. (falta la de salida)
             else grid[i][j]='#';
        }
    }
}

int IsInBounds(unsigned int x, unsigned int y){
 // Devuelve "true" si x e y estan dentro de los límites.
 if (x < 1 || x >= (filas-1)) return false;
 if (y < 1 || y >= (columnas-1)) return false;
 return true;
}

void Visit(unsigned int x, unsigned int y, char **grid){
    // Comenzando en la casilla dada, visita recursivamente cada dirección en orden aleatorio.
    // Se establece la primera ubicación como vacía.
    
    grid[x][y]= ' ';
    // Crea un vector local con las 4 direcciones y cambia aleatoriamente su orden.
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
    // Recorre cada dirección e intenta visitarla.
    for (int i=0; i<4; ++i){
        // dx,dy 
        //are offsets from current location. Set them based
        // on the next direction I wish to try.
        int dx=0, dy=0;
        switch (dirs[i]){
            case ARRIBA: dx = -1; break;
            case ABAJO: dx = 1; break;
            case DERECHA: dy = 1; break;
            case IZQUIERDA: dy = -1; break;
        }
        // (x2,y2) será la posición que se encuantra dos carillas mas allá de la nuestra.
        unsigned int x2 = x + (dx*2);
        unsigned int y2 = y + (dy*2);
        // printf("antes(%u,%u)\n",x,y); //quizás queda más elegante dy<<1 que es lo mismo
        if (IsInBounds(x2,y2)){
            if (grid[x2][y2] == '#'){
                //si (x2,y2) no ha sido visitada todavía, quitamos los '#' entre 
                //nuestra posición actual y (x2,y2).
                grid[x2-dx][y2-dy] = ' ';
                // Visitamos (x2,y2) recursivamente.
                Visit(x2,y2,grid);
            }
        }
    }
}   

void PrintGrid(char **grid){
 // Muestra el laberinto final en la consola.
    for (unsigned int i=0; i<filas; ++i) {
        for (unsigned int j=0; j<columnas; ++j)
            printf("%c",grid[i][j]);
        printf("\n");
    }
}