#ifndef __graf
#define __graf

#include <limits.h>

typedef struct {
    enum {white, gray, black} color;
    int d, f;
    int cheie;
    struct nod_lista *next, *prev;
} t_nod_lista;

typedef struct {
    t_nod_lista *head;
} t_lista;

void init_lista_ad(t_lista *G[]);
void insert_vecini(t_lista *G[], int S);
void print_lista(t_lista *G[]);
void bfs(t_lista *G[], int S);

#endif 