#include <stdio.h>

int quadrado_perfeito(int);


int main () {
    int n;
    printf("Digite um valor: \n");
    scanf("%d", &n);
    if (quadrado_perfeito(n))
        printf("%d eh quadrado perfeito\n", n);
    else
        printf("%d nao eh quadrado perfeito\n", n);
    return 0;
}

int quadrado_perfeito(int n){
    int i = 1;
    while(i*i < n)
        i++;
    if (i*i == n)
        return 1;
    return 0;
    
}