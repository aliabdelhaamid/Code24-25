#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool Anagrama(char palabra1[], char palabra2[]){
    int count = 0;
         
    if (strlen(palabra1) != strlen(palabra2))
    {
        printf("Si no tiene ni la misma cantidad de letras, es imposible que sea anagramas\n");
        return false;
    }
    else if (strcmp(palabra1, palabra2) == 0 )
    {
        printf("Dos palabras exactamente iguales no son anagramas.\n");
        return false;
    }

    
    int count1[256] = {0};
    int count2[256] = {0};

    // Cuenta la cantidad de veces que aparece una letra en cada palabra, si a de casa aparece dos veces, a = 2, s = 1 i c = 1
    for (int i = 0; i < strlen(palabra1); i++) {
        count1[palabra1[i]]++;
        count2[palabra2[i]]++;
    }

    // Compara si no tiene la cantidad de letras
    for (int i = 0; i < 256; i++) {
        if (count1[i] != count2[i]) {
            printf("No son anagramas\n");
            return false;
        }
    }
   
    printf("Son anagramas\n");

    return true;
} 

int main(){

    char palabra1[30];
    char palabra2[30];

    printf("Dame dos palabras para comprobar que son anagrama o no: ");
    scanf("%s %s", palabra1,palabra2);

    Anagrama(palabra1, palabra2);

    return 0;
}