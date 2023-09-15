#include <stdio.h>
#include <stdlib.h>

void frac(float num, int* inteiro, float* frac){
    //aponta para parte inteira do numero
    *inteiro = (int) num;
    //aponta para a parte fracionaria do numero
    *frac = num - *inteiro;
}

//rascunho 21
int v1[10];
int *v2 = v1;
