//lo voy a ir haciendo todo en un mismo fichero de momento para ir mas rápido
#include <stdio.h>
//definimos las 4 direcciones en las que nos vamos a mover:
#define arriba 0
#define abajo 1
#define derecha 2
#define izquierda 3

//funcion para generar matriz inicial nxn: 
void generarMatriz (int n){ //la tengo que cambiar para que devuelva el puntero a la matriz para asi tener la matriz en main y poder llamar a pintarmatriz
    int i, j;
    char **mat=NULL;

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            mat[i][j]= '#';
        }
    }
    return 0;
}

void pintarMatriz (char **mat){ 
    int i, j, n, m;
     for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            printf("%c", mat[i][j]);
        }
    }
    return 0;
}

int main(){
    int n;
    printf("de que tamaño quieres el laberinto?");
    scanf("%d", &n);
    generarMatriz(n);
    return 0;

}