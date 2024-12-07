#include <stdio.h>

int main(){

    int f[50];
    
    f[0] = 0;
    f[1] = 1;
    
    for (int i = 2; i < 50; i++)
    {
       f[i] = f[i - 1] + f[i - 2];
    }
    for (int i = 0; i < 50; i++)
    {
        printf("%d ", f[i]);    
    }
    
    printf("\n");
    
    return 0;

}