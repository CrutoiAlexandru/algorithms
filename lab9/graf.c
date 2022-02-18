#include "graf.h"

extern int N;

void makenull(t_lista *lista){
    if(lista != NULL){
        lista->head = NULL;
    }else{
        printf("Makenull: Eroare, s-a transmis un argument NULL\n");
    }
}

void init_lista_ad(t_lista *G[]) {
    for(int i = 1; i <= N; i++) {
        makenull(G[i]);
    }
}

int list_insert(t_lista *lista, t_nod_lista* x) {
	x->next = lista->head;

	if (lista->head != NULL) {
		lista->head->prev = x;
	}

	lista->head = x;
	x->prev = NULL;

	return 1;
}

void insert_vecini(t_lista *G[], int S) {
    t_nod_lista nod;
    int v;
    
    printf("%d", "Nod sursa " + S + ": ");
    G[S]->head->cheie = S;

    printf("Dati vecinii nodului sursa: ")

    do {
        printf("%d", "Vecin cu " + S);
        scanf("%d", v);

        if(v > 0 && v <= N && v != S) {
            nod = (t_nod_lista*)malloc(sizeof(t_nod_lista));
            nod->cheie = v;
            list_insert(G[S], nod);
        }
    } while (v > 0);
}

void print_lista(t_lista *G[]) {
    t_nod_list nod;

    for(int i = 1; i <= N; i++) {
        nod = G[i]->head->next;
        printf("%d", i + ": ");

        while(nod != NULL) {
            printf("%d", nod->cheie);
            nod = nod->next;    
        }
        printf("\n");
    }
}

void bfs(t_lista *G[], int S) {
    t_nod_lista* Q[100];
    t_nod_lista *u, *v;
    int q = -1;

    for(int u = 1; u <= N; u++) {
        if(u != S) {
            G[u]->color = white;
            G[u]->d = INT_MAX;
            G[u]->prev = NULL;
        }
    }

    G[S]->color = gray;
    G[S]->d = 0;
    G[s]->prev = NULL;

    printf("%d", G[S]->cheie);
    mark_visited(G, G[S]->cheie);
    enqueue(Q, S);

    while(Q != NULL) {
        u = dequeue(Q);

        for(int v = 1; v < )
    }
}