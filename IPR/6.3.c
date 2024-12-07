#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define dimensions 10
#define mina 10


void crearTablero (char tablero[dimensions][dimensions]);
void mines (char tablero[dimensions][dimensions]);
void imprimirTablero (char tablero[dimensions][dimensions]);

int main () 
{
    char tablero [dimensions][dimensions];
    crearTablero(tablero);
    mines(tablero);
    imprimirTablero(tablero);
    printf("\n");
    return 0;
}

void crearTablero (char tablero[dimensions][dimensions])
{
        for (int i = 0; i < dimensions; i++)
        {
            for (int j = 0; j < dimensions; j++)
            {
                tablero[i][j] = '0';        
            }
        }
}

void mines (char tablero[dimensions][dimensions])
{
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
 
 void imprimirTablero (char tablero[dimensions][dimensions])
 {
    for (int i = 0; i < dimensions; i++) {
        for (int j = 0; j < dimensions; j++) {
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
} 
