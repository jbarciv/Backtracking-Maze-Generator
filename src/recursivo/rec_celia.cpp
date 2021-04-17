//lo voy a ir haciendo todo en un mismo fichero de momento para ir mas rápido
#include <stdio.h>
//definimos las 4 direcciones en las que nos vamos a mover:
#define arriba 0
#define abajo 1
#define derecha 2
#define izquierda 3

// vbles globales
unsigned int h, w; //h=alto/filas w=ancho/columnas

//prototipos de funciones
void generarMatriz(int, int);
bool contenido (int, int);
void visita (int, int);
void PintarMatriz (char **);

//funcion para generar matriz inicial nxn: 
void generarMatriz (char ** mat){
    int i, j;

    for(i=0; i<h; i++){
        for(j=0; j<w; j++){
           if(i<1 || j<1 || i==h-1 || j==w-1)
           mat[i][j] = '$'; // bordes
           else  mat[i][j]= '#';
        }
    }
}

void pintarMatriz (char **mat){ 
    int i, j;
     for(i=0; i<h; i++){
        for(j=0; j<w; j++){
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int i=0, j=0; // h será el alto y w el ancho de la matriz
    char ** lab = NULL; // es el puntero que nos dara las casillas del laberinto
    printf("de qué tamaño quieres el laberinto?");
    printf("\n Alto:");
    scanf("%d", &h);
    printf("\n Ancho:");
    scanf("%d", &w);
    h+=2;
    w+=2; //incluimos bordes
    generarMatriz(lab);
    return 0;

}