#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gera(int *, int);
void exibe(char *, int *, int);
void bubble(int *, int, int *, int *);
void inverte(char *,int *, int);

int main() {
    int *v, n, trocas=0, comparacoes=0;
    //inicializando o gerador pseudo-randômico 
    srand(time(0));
    printf("Digite o tamanho do vetor, 0 encerra: ");
    scanf("%d", &n);
    //repetir enquanto tamanho > 0
    while(n > 0) {
        //alocar um vetor dinamicamente, do tamanho que o usuário escolher
        v = (int *) malloc (n * sizeof(int));
        //gerar randomicamente os valores para o vetor
        gera (v, n);
        //exibir 
        exibe ("vetor gerado", v, n);
        //bubble
        bubble(v, n, &comparacoes, &trocas);
        //exibir
        exibe("vetor ordenado", v, n);
        printf("\nnumero de troca: %d\n", trocas);
        printf("numero de comparacoes: %d\n", comparacoes);
        
        inverte("vetor invertido", v, n);

        //ler novo tamanho

        free(v);
        comparacoes = 0;
        trocas = 0;

        printf("\nDigite o tamanho do vetor, 0 encerra: ");
        scanf("%d", &n);
    }
    return 0;
}


void gera(int *v, int n){
    int i;
    for(i=0; i<n; i++)
        v[i] = rand() % (n*10); 
}

void exibe (char * msg, int *v, int n){
    int i;
    printf("\n%s\n", msg);
    for(i=0; i<n; i++)
        printf("%d |", v[i]);
}

void bubble (int *v, int n, int *comparacoes, int *trocas){
    int i, j, aux;
    for(i=1; i<n; i++){
        *comparacoes = *comparacoes + 1;
        for(j=0; j<n-i; j++){
            if(v[j] > v[j+1]){ //troca
                *trocas = *trocas + 1;
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

void inverte(char * msg, int *v, int n){
    int i;
    printf("\n%s\n", msg);
    for(i=n-1; i>=0; i--)
        printf("%d |", v[i]);
}