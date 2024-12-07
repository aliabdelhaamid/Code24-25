#include <stdio.h>
#include <stdlib.h>
// escriure una función que li dones dos valors i tels intercambie, gastant lo del swap.

int swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return 1; // Indicate success
}

int main() {
    int x = 4, y = 2;
    swap(&x, &y);
    printf("%d %d\n", x, y);
     
    return 0;
}