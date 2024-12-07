#include <stdio.h>
#include <ctype.h>

typedef struct{
    char matrícula[8];
    int horas, minutos;
    float tarifa;
}vehículo;

int comprobar_matricula(vehículo *v1){
    for (int i = 0; i < 4; i++) {
        if (!isdigit(v1->matrícula[i])) {
            return 0;
        }
    }
    for (int i = 4; i < 7; i++) {
        if (!isalpha(v1->matrícula[i])) {
            return 0;
        }
    }
    return 1;
}

int comprobar_hora(vehículo *v1){
    int total = v1->horas * 60 + v1->minutos;
    if (total >= 0 && total < 1440 && v1->minutos < 60) {
        return 1;
    } 
    return 0;
}

int comprobar_tarifa(vehículo *v1){

    if (v1->tarifa > 0)
    {
        return 1;
    }
    else return 0;

}
void leer_datos(vehículo *v1){
    do
    {
        printf("Dame tu matrícula de coche: ");
        scanf("%s", v1->matrícula);
    
        printf("Dame la hora de entrada: " );
        scanf("%d:%d", &v1->horas, &v1->minutos);

        printf("Dame la tarifa: ");
        scanf("%f",&v1->tarifa);
   
        if (comprobar_hora(v1) && comprobar_matricula(v1) && comprobar_tarifa(v1))
        {
            printf("Datos almacenados correctamente\n");
        }
    } while(!comprobar_matricula(v1) || !comprobar_hora(v1) || !comprobar_tarifa(v1));
}
int main(){
    vehículo v1;
    leer_datos(&v1);
    return 0;
}