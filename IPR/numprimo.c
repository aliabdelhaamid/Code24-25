#include <stdio.h>

int main(){
    int num;
    printf("Dame un num: ");
    scanf("%d", &num);
    int count = 0;
    for (int i = num; i > 0; i--)
    {
        if (num % i == 0 )
        {
            count += i;
        }
    }

    if(count == num + 1 || num == 1){
        printf("Es un numero primo\n");
        for (int j = 1 ; j < 101; j++)
        {
            printf("%d ", j);
        }
    }
    else printf("No es un número primo");
    printf("\n");

    return 0;
}