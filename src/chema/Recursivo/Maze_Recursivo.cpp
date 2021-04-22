#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>



using namespace std;
//----CONSTANTES--------------------------------------------------------
#define ARRIBA 0
#define DERECHA 1
#define ABAJO 2
#define IZQUIERDA 3
//----VARIABLES GLOBALES------------------------------------------------
int columnas,filas;
double k=0;
//----PROTOTIPO DE FUNCIONES--------------------------------------------
void Arreglar_2D();
void SetGrid(char **);
int IsInBounds( int , int );
int Visit(int , int , char **);
void PrintGrid(char **);
//----FUNCIONES--------------------------------------------------------
int main(){
   int i;
   // Se pide al usuario el tamaño del laberinto.
    printf("Introduzca dimensiones\n Filas: ");
    scanf("%d", &filas);
    printf(" Columnas: ");
    scanf("%d", &columnas);

    Arreglar_2D();
    
    char **grid = NULL;
    // Se reserva memoria para el vector de vectores dinámicos (del tamaño de "filas").
  	grid = (char **) malloc (filas * sizeof(char *)); 
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
    
    
    printf("todo perfecto! antes de SetGrid\n");
    SetGrid(grid);
    printf("todo perfecto! despues de SetGrid\n");
    Visit(1,1,grid); // Función recursiva.
    PrintGrid(grid);
    printf("¡Hemos salido de Visit!\n");
    printf("Nº iteraciones= %f\n", k);
    
    // Se libera memoria para cada fila.
    for (i = 0; i < filas; ++i) {
    	free(grid[i]);
    }
  	free(grid); //Se libera memoria para el vector de vectores ("primera columna").
    printf("todo perfecto!\n");
    return 0;
}

void Arreglar_2D(){
    (filas%2)?filas:filas+=1;
    (columnas%2)?columnas:columnas+=1;
}

void SetGrid(char **grid){
    // Rellenamos la malla con carácter '#' y creamos un doble cascarón de vacíos ' '.
    int i,j;
    for (i=0; i<filas; ++i){
        for(j=0; j<columnas; ++j)
            grid[i][j]='#';
    }
}

int IsInBounds(int x, int y){
 // Devuelve "true" si x2 e y2 estan dentro de los límites.
 if (x < 1 || x > (filas-2)) return false;
 if (y < 1 || y > (columnas-2)) return false;
 return true;
}

int Visit(int x, int y, char **grid){
    // Comenzando en la casilla dada, visita recursivamente cada dirección en orden aleatorio.
    // Se establece la primera ubicación como vacía.
    
    k++;
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
        // dx,dy are offsets from current location. Set them based
        // on the next direction I wish to try.
        int dx=0, dy=0;
        switch (dirs[i]){
            case ARRIBA: dx = -1; break;
            case ABAJO: dx = 1; break;
            case DERECHA: dy = 1; break;
            case IZQUIERDA: dy = -1; break;
        }
        // Find the (x,y) coordinates of the grid cell 2 spots
        // away in the given direction.
        int x2 = x + (dx*2);
        int y2 = y + (dy*2);
        // printf("antes(%u,%u)\n",x,y); //quizás queda más elegante dy<<1 que es lo mismo
        if (IsInBounds(x2,y2)){
            if (grid[x2][y2] == '#'){
                // (x2,y2) has not been visited yet... knock down the
                // wall between my current position and that position
                grid[x2-dx][y2-dy] = ' ';
                // Recursively Visit (x2,y2)
                Visit(x2,y2,grid);
            }
        }
    }
    return k;
}   

void PrintGrid(char **grid){
 // Muestra el laberinto final en la consola.
    for (int i=0; i<filas; i++) {
        for (int j=0; j<columnas; j++)
            if (grid[i][j]=='#'){
                cout << "\u2B1C";
            }
            else {
                cout << "  ";
            }
            // printf("%c",grid[i][j]);
        printf("\n");
    }
    printf("filas= %d, columnas=%d", filas, columnas);
}// si para hacer pruebas con numero to grandes..