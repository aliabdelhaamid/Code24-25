#include <stdio.h>

int main(void){
    double c;
    c = - 3.0;

    double d = c / 0.0;
    double *pD = &d;
    printf("Valor de d: %lf\n", d);
    printf("Dirección de d: %p\n", (void*)pD);
    return 0;
}