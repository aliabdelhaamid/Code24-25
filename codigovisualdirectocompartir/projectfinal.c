#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define dim 50 // macro jijija
#define posIniX 1 //(dim / 2)
#define posIniY 1 //(dim / 2)
#define obstaculo 64


void crearMundo(char mundo[dim][dim]); // funcion decorativa 
void obstaculos(char mundo[dim][dim]); // funcion decorativa
void imprimirMundo (char mundo[dim][dim], int *x, int *y); // funcion decorativa
void moverse(char mundo[dim][dim], int *x, int *y); // función decorativa, moverse izquierda o derecha, arriba o abajo

int main()
{
    int x,y;
    char mundo[dim][dim]; // array 2D amb la q anem a fer el món
    crearMundo(mundo); // cridem a la funció
    obstaculos(mundo); // cridem a la funció
    imprimirMundo(mundo, &x, &y); // cridem a la funció
    moverse(mundo, &x, &y);

    printf("\n"); // quan acabe que imprimixga una nova línea pa dixar espai
    return 0;
}

void crearMundo(char mundo[dim][dim]){
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            // el if sustituix la primera i la ultima fila amb asteriscos
            if (i == 0 || i == dim-1 || j == 0 || j == dim-1)      mundo[i][j] = '*';
            // posicionem el robot al mig
            else if(i == posIniX && j == posIniY) mundo[i][j] = 'R';
            // i completem la resta del mon amb espais en blanc
            else mundo[i][j] = ' ';   
        } 
    }
}

void obstaculos(char mundo[dim][dim])
{
    srand(time(NULL));
    int obstcol = 0;
    while (obstcol < obstaculo)
    {
    int fila = rand() % dim;
    int columna = rand() % dim;
    
        if (mundo[fila][columna] == ' ')
        {
            mundo[fila][columna] = '-';
            obstcol++;
        }
    }
}

void imprimirMundo (char mundo[dim][dim], int *x, int *y)
{
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            printf("%c ", mundo[i][j]);
        }
        printf("\n");
    }
    printf("Ahora mismo estas en (1,1)\n");
    printf("Hacia donde quieres ir, (x,y)? ");
    scanf("%d,%d", x, y);

}

void moverse(char mundo[dim][dim], int *on_vuicanarx, int *on_vuicanary){
    
    int on_esticx = posIniX;
    int on_esticy = posIniY; 

    do {
        if(on_esticy > *on_vuicanary){
            mundo[on_esticx][on_esticy] = ' ';
            on_esticy -= 1;
            if (mundo[on_esticx][on_esticy] == '-') on_esticy += 2;
            mundo[on_esticx][on_esticy] = 'R';   
        }
        else{
            mundo[on_esticx][on_esticy] = ' ';
            on_esticy += 1;
            if (mundo[on_esticx][on_esticy] == '-') on_esticy -= 2;
            mundo[on_esticx][on_esticy] = 'R';   
        }   
        if(on_esticx > *on_vuicanarx){
            mundo[on_esticx][on_esticy] = ' ';
            on_esticx -= 1;
            if (mundo[on_esticx][on_esticy] == '-') on_esticx += 2;
            mundo[on_esticx][on_esticy] = 'R';   
        }
        else{
            mundo[on_esticx][on_esticy] = ' ';
            on_esticx += 1;
            if (mundo[on_esticx][on_esticy] == '-') on_esticx -= 2;
            mundo[on_esticx][on_esticy] = 'R';   
        }
        printf("(%d,%d)", on_esticx, on_esticy);     
    }
    while (on_esticy != *on_vuicanary && on_esticx != *on_vuicanarx);

} // falta fer quan se troba un obstacul en menejantse per columnes i files




// alternativa a avanzar o girar //
/*
void avanzar_girar (char mundo[dim][dim]){
int x = posIniX;
int y = posIniY;
if (mundo[x][y] == 'R'){
    if (mundo[x][y+1] == ' ')
        mundo[x][y] = ' ';
        mundo[x][y+1] = 'R'
    }
    else if (mundo[x+1][y] == ' '){
            mundo[x][y] = ' ';
            mundo[x+1][y] = 'R';
        }
    else if (mundo[x][y-1] == ' '){
            mundo[x][y] = ' ';
            mundo[x][y-1] = 'R';
        }
    else if (mundo[x-1][y] == ' '){
            mundo[x][y] = ' ';
            mundo[x-1][y] = 'R';
        }
    else if (mundo[x+1][x+1] == ' '){
            mundo[x][y] = ' ';
            mundo[x+1][y+1] = 'R';
        }
    else if (mundo[x-1][y-1] == ' '){
            mundo[x][y] = ' ';
            mundo[x-1][y-1] = 'R';
        }
    else if (mundo[x+1][y-1] == ' '){
            mundo[x][y] = ' ';
            mundo[x+1][y-1] = 'R';
        }
    else if (mundo[x-1][y+1] == ' '){
            mundo[x][y] = ' ';
            mundo[x-1][y+1] = 'R';
        }
    }
}
 esto se puede hacer con un: for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                    if (mundo[x][y] == ' ')
                    mundo[x][y] = ' ';
                    mundo[x][y] = 'R
                    }
                }
    Que comprueba todas las posiciones de x e y

*/