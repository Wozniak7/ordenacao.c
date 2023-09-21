#include <stdio.h>
#include <stdlib.h>


void frac(float, int*, float*);

int main (){
    float num, frac_num;
    int inteiro;
    printf("Digite um numero: ");
    scanf("%f", &num);
    frac(num, &inteiro, &frac_num);
    
    return 0;
}

void frac(float num, int* inteiro, float* frac){
    *inteiro = (int)num;
    *frac = num - *inteiro;
    printf("inteiro: %d\n", *inteiro);
    printf("fracionario: %f\n", *frac);

}


//rascunho 21
// int v1[10];
// int *v2 = v1;
