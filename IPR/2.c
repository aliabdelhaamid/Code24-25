#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define dimensions 10
#define mina 10


void crearTablero (char tablero[dimensions][dimensions]);
void mines (char tablero[dimensions][dimensions]);
void pistasTablero(char tablero[dimensions][dimensions]);
void imprimirTablero (char tablero[dimensions][dimensions]);
void otroTablero(char tablero[dimensions][dimensions]);

int main () 
{
    char tablero [dimensions][dimensions];
    crearTablero(tablero);
    mines(tablero);
    pistasTablero(tablero);
    otroTablero(tablero);
    imprimirTablero(tablero);
    printf("\n");
    return 0;
}

void crearTablero (char tablero[dimensions][dimensions]){
        for (int i = 0; i < dimensions; i++)
        {
            for (int j = 0; j < dimensions; j++)
            {
                tablero[i][j] = '0';        
            }
        }
}

void mines (char tablero[dimensions][dimensions]){
    srand(time(NULL));
    int minascol = 0;
    while (minascol < mina)
    {
    int fila = rand() % dimensions;
    int columna = rand() % dimensions;
    
        if (tablero[fila][columna] != 'M')
        {
            tablero[fila][columna] = 'M';
            minascol++;
        }
    }
}
void pistasTablero(char tablero[dimensions][dimensions]){
    for(int i = 0; i < dimensions; i++)
    {
        for(int j = 0; j < dimensions; j++)
        {
            if(tablero[i][j] == 'M')
            {
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        int nfila = i + x;
                        int ncolumna = j + y;
                        if (nfila >= 0 && nfila < dimensions && ncolumna >= 0 && ncolumna < dimensions && tablero[nfila][ncolumna] != 'M')
                        {
                            tablero[nfila][ncolumna]++;
                            
                        }
                    }
                }
            }
       
        }
    }
}

void imprimirTablero (char tablero[dimensions][dimensions])
 {
        for (int i = 0; i < dimensions; i++) {
            for (int j = 0; j < dimensions; j++) {
                printf("%c ", tablero[i][j]);
            }
            //printf("\n");
        }
} 
void otroTablero(char tablero[dimensions][dimensions])
{
    char tablero2[dimensions][dimensions];
    int fila, columna;
    do{
        for (int i = 0; i < dimensions; i++){
            for (int j = 0; j < dimensions; j++){
                tablero2[i][j] = '.';
                printf("%c ", tablero2[i][j]);
            }
            printf("\n");
        }
        printf("Dime la casilla que quieras destapar, mediante su fila(0-9) y columna(0-9): ");
        scanf("%d %d",&fila, &columna);
        if (tablero2[fila][columna] && tablero[fila][columna] == 'M')
            {
             tablero[fila][columna] = '*';
            }
        else if (tablero2[fila][columna] && tablero[fila][columna] != 'M')
        {
                tablero[fila][columna] = '.';
            }
        else if (tablero2[fila][columna] && tablero[fila][columna] == '0')
           {
            tablero[fila][columna] = ' ';
            }
    }while(fila > 0 || fila < 9 || columna > 0 || columna < 9);
}





