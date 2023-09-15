#include <stdio.h>

void desenha_triangulo(int);


int main () {
    int n;
    printf("Digite um valor: \n");
    scanf("%d", &n);
    desenha_triangulo(n);
    return 0;
}

void desenha_triangulo(int n){
    int i, l=1, k, m;
    for( ; l<=n; l++){
        k = 2*l - 1;
        m = k/2;
        for (i = 1; i <= 40 - m; i++)
            printf(" ");
        for (i = 1; i<=k; i++)
            printf("*");
        printf("\n");
    }
    
}