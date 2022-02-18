#include "graf.h"

extern int N;

int main() {
    int S;
    t_lista G[100];

    printf("Nr noduri = ");
    scanf("%d",&N);

    init_lista_ad(&G);

    for(int i = 1; i <= N; i++) {
        insert_vecini(&G, i);
    }

    printf("Lista adiacenta: ");
    print_lista(&G);

    printf("Parcurgere in latime: ");
    printf("Nod start: ")
    scanf("%d",&S);
    bfs(&G, S);
}