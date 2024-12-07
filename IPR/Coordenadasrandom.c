#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Coordenadasrandom
{
    float x;
    float y;
};

int main(){
    srand(time(NULL)); // genera nuevos números aleatorios
    struct Coordenadasrandom p = {(float)rand()/RAND_MAX * 10, (float)rand()/RAND_MAX * 10};

    printf("Coordenadas: (%.2f,%.2f)\n", p.x,p.y);
    
    return 0;
}