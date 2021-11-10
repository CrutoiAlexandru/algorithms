#include "binary_tree/binary_tree.h"

int main(){
    t_arbore t;
    t_nod_arb n, r, s;
    int x;

    printf("Nodeul radacina cu cheia x = ");
    scanf("%d", &x);

    r = make_root(&t, x);

    printf("Introduceti x pana la citirea 0 \n");
    printf("x = ");
    scanf("%d", &x);

    while(x != 0){
        n = create_node(x);
        tree_insert(&t, &n);
    }

    printf("IN-order walk:\n");
    inorder_walk(&r);

    printf("Pre-order walk\n");
    preorder_walk(&r);

    printf("Post-order walk\n");
    postorder_walk(&r);

    printf("\n");
    printf("Regasire nod cu cheia x = ");
    scanf("%d", x);

    n = it_tree_search(&r, x);

    if(&n != NULL){
        printf("Nodul cu cheia %d gasit iterativ\n", n.key);
    }else{
        printf("Nodul nu a fost gasit iterativ \n");
    }

    n = tree_search(&r, x);

    if(&n != NULL){
        printf("Nodul cu cheia %d gasit", n.key);
    }else{
        printf("Nodul nu a fost gasit recursiv\n");
    }

    n = tree_min(&r);
    printf("Tree minimum: %d", n.key);

    n = tree_max(&r);
    printf("Tree maximum: %d", n.key);

    printf("Succesorul lui x = ");
    scanf("%d", x);

    n = tree_search(&r, x);

    s = tree_succesor(&n);
}