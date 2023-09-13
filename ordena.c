#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gera(int *, int);
void exibe(char *, int *, int);
void bubble(int *, int, int *, int *);
//void selectionsort(int *, int, int *, int *);
//void insertionsort(int *, int, int *, int *);
void inverte(int *, int);
void semi_ordenado(int *, int);
void vetor_repetido(int *, int);
int busca_simples (int *, int , int );
int busca_ocorrencias(int *, int, int);


int main() {
    int *v, n, trocas=0, comparacoes=0, x=0;
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
        //selection
        //selectionsort(v, n, &comparacoes, &trocas);
        //insertion
        //insertionsort(v, n, &comparacoes, &trocas);
        //exibir
        exibe("vetor ordenado", v, n);
        printf("\nnumero de troca: %d\n", trocas);
        printf("numero de comparacoes: %d\n", comparacoes);
        comparacoes = 0;
        trocas = 0;

        //busca simples
        printf("\nDigite o valor que voce procura: \n");
        scanf("%i", &x);
        int bs = busca_simples(v, n, x);
        int bo = busca_ocorrencias(v, n, x);
        printf("\nO indice do numero procurado eh: %i", bs);
        printf("\nO numero de ocorrencias eh: %i\n", bo);
        
        //bagunçar o vetor 
        semi_ordenado(v, n);
        exibe("Vetor semi_ordenado", v, n);
        //bubble
        bubble(v, n, &comparacoes, &trocas);
        //selection
        //selectionsort(v, n, &comparacoes, &trocas);
        //insertion
        //insertionsort(v, n, &comparacoes, &trocas);
        //exibir
        exibe("vetor ordenado", v, n);
        printf("\nnumero de troca: %d\n", trocas);
        printf("numero de comparacoes: %d\n", comparacoes);
        comparacoes = 0;
        trocas = 0;

        //inverter o vetor
        inverte(v, n);
        exibe("Vetor invertido", v, n);
      
        //gerar vetor com numeros repetidos
        vetor_repetido(v, n);
        exibe("\nVetor com numeros repetidos", v, n);
        //bubble
        bubble(v, n, &comparacoes, &trocas);
        //selection
        //selectionsort(v, n, &comparacoes, &trocas);
        //insertion
        //insertionsort(v, n, &comparacoes, &trocas);
        //exibir
        exibe("vetor ordenado", v, n);
        printf("\nnumero de troca: %d\n", trocas);
        printf("numero de comparacoes: %d\n", comparacoes);

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

void inverte(int *v, int n){
    int i;
    int aux;
    for(i=0; i<n/2; i++){
        aux=0;
        aux=v[i];
        v[i]=v[n-i-1];
        v[n-i-1]=aux;
    }
}

void semi_ordenado(int *v, int n){
    int i;
    for(i=0; i<n; i++){
          int j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = v[j];
          v[j] = v[i];
          v[i] = t;
    }
}

void vetor_repetido(int *v, int n){
    int i;
    for(i=0; i<n; i++){
        v[i] = rand() % (n/2);
    }
}

int busca_simples (int *v, int n, int x){
    int i;
    for(i=0; i<n; i++){
        if(v[i] == x)
            return i;
            
        }
    return -1;
}

int busca_ocorrencias(int *v, int n, int x){
    int i, cont=0;
    for(i=0; i<n; i++){
        if(v[i] == x
        )
            cont++;
    }
    return cont;
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

// void insertionsort ( int v[], int n, int *comparacoes, int *trocas){
//     int j, i,aux;
//     for ( j = 1; j < n; ++j) {
//         aux = v[j];
//             for (i = j-1; i >= 0 && v[i] > aux; --i)
//                 v[i+1] = v[i];
//                 v[i+1] = aux;
//         }
//     }

// void selectionsort ( int v[],int n, int *comparacoes, int *trocas )
// {
//    for (int i = 0; i < n-1; ++i) {
//   int min = i;
//   for (int j = i+1; j < n; ++j)
//      if (v[j] < v[min])  min = j;
//       int aux = v[i]; v[i] = v[min]; v[min] = aux;
//    }
// }