#include <stdio.h>

#define dim 50 // macro jijija

typedef struct{
    int casilla;
    int obstaculo;
    int libre;
} Robot;

void crearMundo(char mundo[dim][dim]); // funcion decorativa 

int main(){

    char mundo[dim][dim]; // array 2D amb la q anem a fer el món
    crearMundo(mundo); // cridem a la funció

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
            else if(i == dim/2 && j == dim/2) mundo[i][j] = 'R';
            // i completem la resta del mon amb espais en blanc
            else                           mundo[i][j] = ' ';
            // imprimim el món, dixem espai pa q se faja cuadrat :)
            printf("%c ", mundo[i][j]);       
        }
        printf("\n"); // molt important, pa quan acabe amb cada fila que bote a la seguent, 
                      //sense aço seria un desatre
    }
}

void movimientos(char mundo[dim][dim]){
    Robot r1;
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            if (mundo[i][j] == '*'){
                r1.obstaculo;
        }   
            
            else if(mundo[i][j] == ' '){

        }  
        }
    } 

}