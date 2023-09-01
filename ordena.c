#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gera_vetor (int *v, int n) {
    int i ;
    for (i=0; i<n; i++){
        v[i] = rand() % (n*10);
    }
}

void exibe_vetor (int *v, int n, char * msg){
    int i;
    printf("\n%s\n", msg);
    for (i=0; i<n; i++){
        printf("%d ", v[i]);
    }
}


void bubble_sort (int *comparacoes, int *trocas, int *v, int n){
int i, j, aux;
for (i=1; i<n; i++){
    //contar comparações
    *comparacoes = *comparacoes + 1;
    for (j=0; j<n-i; j++) {
        //contar comparações
        if (v[j] > v[j+1]) {
            *trocas = *trocas +1;
            aux = v[j];
            v[j] = v[j+1];
            v[j+1] = aux;
            }
        }
    }
}


// void insertionsort ( int v[], int n){
//     int j, i,aux;
//     for ( j = 1; j < n; ++j) {
//         aux = v[j];
//             for (i = j-1; i >= 0 && v[i] > aux; --i)
//                 v[i+1] = v[i];
//                 v[i+1] = aux;
//         }
//     }

// void selectionsort ( int v[],int n )
// {
//    for (int i = 0; i < n-1; ++i) {
//   int min = i;
//   for (int j = i+1; j < n; ++j)
//      if (v[j] < v[min])  min = j;
//       int aux = v[i]; v[i] = v[min]; v[min] = aux;
//    }
// }


int main () {
int n;
int *v;
long ini, fim;
int trocas = 0;
int comparacoes = 0;
printf("Digite o tamanho do vetor (0 encerra): ");
scanf("%d", &n);

srand (time(0));

while (n > 0){

v = (int *) malloc (n*sizeof(int));

gera_vetor(v, n);

exibe_vetor(v, n, "Vetor gerado");

 ini = time(0);

bubble_sort(&comparacoes, &trocas, v, n);

// insertionsort(v, n);

// selectionsort(v,n);

fim = time(0);

exibe_vetor(v, n, "Vetor ordenado");

printf("\ntempo de ordenacao: %ld\n ", fim-ini);

printf("\nnumero de comparacoes: %d\n ", comparacoes);
printf("\nnumero de trocas: %d\n ", trocas);

free(v);


printf ("Digite o tamanho do vetor (0 encerra): ");

scanf("%d", &n);

    }
return 0;
}