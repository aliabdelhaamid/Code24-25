#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Coordenadas
{
    float x;
    float y;
};
void aleatorio(struct Coordenadas *p){
    p->x= (float)rand()/RAND_MAX * 1;
    p->y = (float)rand()/RAND_MAX * 1;
}
int main(){
    srand(time(NULL)); // genera nuevos números aleatorios
    rand();
    struct Coordenadas p;
    aleatorio(&p);
    printf("Coordenadas: (%.2f,%.2f)\n", p.x,p.y);
    
    return 0;
}