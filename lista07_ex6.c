#include <stdio.h>

void segundos(int, int, int);


int main (){
    int h, m, s;
    printf("digite o valor de horas, minutos e segundos: \n");
    scanf("%d%d%d", &h,&m,&s);
    segundos(h, m, s);

    return 0;
}

void segundos(int h, int m, int s){
    int soma = (h*3600) + (m*60) + s;
    printf("tempo em segundos: %d\n", soma);
}