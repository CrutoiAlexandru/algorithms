#include "binary_tree.h"

t_nod_arb  make_root(t_arbore *a, int key){
    a->root = (t_nod_arb*)malloc(sizeof(t_nod_arb));
    a->root->key = key;
    a->root->left = NULL;
    a->root->right = NULL;
    a->root->parent = NULL;

    return *a->root;
}

t_nod_arb  create_node(int key){
    t_nod_arb *n;
    n = (t_nod_arb*)malloc(sizeof(t_nod_arb));
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    n->parent = NULL;

    return *n;
}

void tree_insert(t_arbore *a, t_nod_arb *n){
    t_nod_arb *y, *x;
    y = NULL;
    x = a->root;

    while(x != NULL){
        y = x;
        if(n->key < x->key){
            x = x->left;
        }else{
            x = x->right;
        }
    }

    n->parent = y;

    if(y == NULL){
        a->root = n;
    }else if(n->key < y->key){
        y->left = n;
    }else{
        y->right = n;
    }
}

void inorder_walk(t_nod_arb *root){
    if(root != NULL){
        inorder_walk((root->left));
        printf("%d", root->key);
        inorder_walk(root->right);
    }
}

void preorder_walk(t_nod_arb *root){
    if(root != NULL){
        printf("%d", root->key);
        preorder_walk(root->left);
        preorder_walk(root->right);
    }
}

void postorder_walk(t_nod_arb *root){
    if(root != NULL){
        postorder_walk(root->left);
        postorder_walk(root->right);
        printf("%d", root->key);
    }
}

t_nod_arb it_tree_search(t_nod_arb *n, int key){
    while(n != NULL && key != n->key){
        if(key < n->key){
            n = n->left;
        }else{
            n = n->right;
        }
    }

    return *n;
}

t_nod_arb  tree_search(t_nod_arb *n, int key){
    if(n == NULL || key == n->key){
        return *n;
    }
    if(key < n->key){
        return tree_search(n->left, key);
    }else{
        return tree_search(n->right, key);
    }
}

t_nod_arb tree_min(t_nod_arb *n){
    while(n->left != NULL){
        n = n->left;
    }

    return *n;
}

t_nod_arb tree_max(t_nod_arb *n){
    while(n->right != NULL){
        n = n->right;
    }

    return *n;
}

t_nod_arb tree_succesor(t_nod_arb *n){
    t_nod_arb *y;

    if(n->right != NULL){
        return tree_min(n->right);
    }

    y = n->parent;

    while(y != NULL && n == y->right){
        n = y;
        y = y->parent;
    }

    return *y;
}