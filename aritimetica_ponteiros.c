#include <stdio.h>
#include <stdlib.h>

int main () {
    int *v = (int *) malloc (10 * sizeof(int));
    int i;
    printf("vetor:\n");

    for(i=0; i<10; i++){
        *(v+i) = i;
        printf("\nposicao %p, valor %d", v+i, *(v+i));
    }

    // for (i=0; i<10; i++)
    //     printf("\n%p", v+i);
    // printf("\n\nvalores dos enderecos:\n");
    // for (i=0; i<10; i++){
    //     *(v+i) = i;
    //     printf("%d, ", *(v+i));
    // }
    
    return 0;
}