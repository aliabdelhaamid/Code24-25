#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define dim 50 // macro jijija
#define posIniX 1 //(dim / 2)
#define posIniY 1 //(dim / 2)
#define obstaculo 64

void crearMundo(char Mundo[dim][dim]); // funció decorativa 
void obstacles(char Mundo[dim][dim]); // funció decorativa
void imprimirMundo (char Mundo[dim][dim]); // funció decorativa
void moureRobot(char Mundo[dim][dim], int *x, int *y, int mx, int my);
int moureRobotCapA(char Mundo[dim][dim], int *x, int *y, int destX, int destY);

void crearMundo(char Mundo[dim][dim]){
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (i == 0 || i == dim-1 || j == 0 || j == dim-1) {
                Mundo[i][j] = '*';
            } else if(i == posIniX && j == posIniY) {
                Mundo[i][j] = 'R';
            } else {
                Mundo[i][j] = ' ';
            }
        } 
    }
}

void obstacles(char Mundo[dim][dim]) {
    srand(time(NULL));
    int obstcol = 0;
    while (obstcol < obstaculo) {
        int fila = rand() % dim;
        int columna = rand() % dim;
        if (Mundo[fila][columna] == ' ') {
            Mundo[fila][columna] = '-';
            obstcol++;
        }
    }
}

void imprimirMundo (char Mundo[dim][dim]) 
{
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            printf("%c ", Mundo[i][j]);
        }
        printf("\n");
    }
}

void moureRobot(char Mundo[dim][dim], int *x, int *y, int mx, int my) {                     
    int newX = *x + mx; 
    int newY = *y + my;

    if (Mundo[newX][newY] == ' ' || Mundo[newX][newY] == '-') {
        Mundo[*x][*y] = '.'; // Deixa un rastre per saber per on ha pasat
        *x = newX; 
        *y = newY;
        Mundo[*x][*y] = 'R';
        printf("%d, %d\n", *x, *y);
    }
}
int moureRobotCapA(char Mundo[dim][dim], int *x, int *y, int destX, int destY) {
    if (Mundo[destX][destY] == '-' || Mundo[destX][destY] == '*') {
        printf("La posició de destí és un obstacle. No es pot moure el robot.\n");
        return 0;
    }

    while (*x != destX || *y != destY) 
    {
        int mx = 0, my = 0;
        if (*x < destX) mx = 1;
        else if (*x > destX) mx = -1;
        else if (*y < destY) my = 1;
        else if (*y > destY) my = -1;

        if (Mundo[*x + mx][*y + my] == '-' || Mundo[*x + mx][*y + my] == '*') 
        {
            if (mx != 0) {
                if (Mundo[*x][*y + 1] == ' ') my = 1;
                else if (Mundo[*x][*y - 1] == ' ') my = -1;
            } else if (my != 0) {
                if (Mundo[*x + 1][*y] == ' ') mx = 1;
                else if (Mundo[*x - 1][*y] == ' ') mx = -1;
            }
        }

        moureRobot(Mundo, x, y, mx, my);
    }
    return 1;
}

int main() {
    int x = posIniX, y = posIniY;
    char Mundo[dim][dim];
    crearMundo(Mundo);
    obstacles(Mundo);
    imprimirMundo(Mundo);

    int destX, destY;
    printf("Introduïu les coordenades de destí (x y): ");
    scanf("%d %d", &destX, &destY);

    int mundoFinal = moureRobotCapA(Mundo, &x, &y, destX, destY);

    if (mundoFinal) {
        imprimirMundo(Mundo);
    }

    return 0;
}
 