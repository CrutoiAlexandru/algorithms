#include <stdio.h>
#include "commands.h"

int main(){
    t_rb_arbore t;
    t_rb_node r, n;
    int x;

    printf("ROOT = ");
    scanf("%d", &x);

    r = make_root(&t, x);

    printf("Introduceti x pana la citirea 0\n");
    printf("x = ");
    scanf("%d", &x);

    while(x != 0){
        n = create_node(x);
        rb_insert(&t, &n);
        printf("x = ");
        scanf("%d", &x);
    }

    printf("In-order walk: ");
    inorder_walk(&r);

    printf("\n");

    printf("Cauta nod cu cheia x = ");
    scanf("%d", &x);
    
    n = tree_search(&r, x);

    if(&n != NULL){
        printf("Nodul cu cheia %d gasit", n.key);
    }else{
        printf("Nodul nu a fost gasit");
    }
}