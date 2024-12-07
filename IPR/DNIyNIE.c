#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char DNI[9]; // 8 + '\0'.
    char num;

}NIF; // hecho

void comprobarDNIyNIE(NIF n1){
    int n = atoi(n1.DNI);
    char listaLetras[] = {'T', 'R', 'W', 'A', 'G', 'M', 'Y', 'F', 'P', 'D', 'X', 'B', 'N', 'J', 'Z', 'S', 'Q', 'V', 'H', 'L', 'C', 'K', 'E'};
    //  0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17  18  19  20  21  22
    //  T  R  W  A  G  M  Y  F  P  D   X   B   N   J   Z   S   Q   V   H   L   C   K   E
    
    int pareja = n % (sizeof(listaLetras) / sizeof(listaLetras[0])); // dividir el número de tu DNI entre el número d letras(23).
    for (int i = 0; i < sizeof(listaLetras)/sizeof(listaLetras[0]); i++)
    {
        if (pareja == i)
        {
            printf("Tu letra correspondiente es %c, ",listaLetras[i]);
        }
    }
    if (n1.num == listaLetras[pareja])
    {
        printf("muy bien, has escrito la letra correcta.\n");
    }
    else printf("%c no es la letra correcta.\n", n1.num);
    
}

int main(){
    NIF n1;
    printf("Dame tu DNI o NIE, número y letra por separado: ");
    scanf("%s %c", n1.DNI, &n1.num);
    
    if (n1.DNI[0] == 'X' || n1.DNI[0] == 'x')
    {
        n1.DNI[0] = '0';
        comprobarDNIyNIE(n1);
    }
    else if (n1.DNI[0] == 'Y' || n1.DNI[0] == 'y')
    {
        n1.DNI[0] = '1';
        comprobarDNIyNIE(n1);
    }
    else if (n1.DNI[0] == 'Z' || n1.DNI[0] == 'z')
    {
        n1.DNI[0] = '2';
        comprobarDNIyNIE(n1);
    }
    else comprobarDNIyNIE(n1);
    
    return 0;
}


