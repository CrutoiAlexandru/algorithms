#include "commands.h"
#include <stdlib.h>
#include <stdio.h>

t_rb_node make_root(t_rb_arbore *a, int key){
    a->root = (t_rb_node*)malloc(sizeof(t_rb_node));

    a->root->key = key;
    a->root->left = NULL;
    a->root->right = NULL;
    a->root->parent = NULL;
    a->root->color = black;
    
    return *a->root;
}

t_rb_node create_node(int key){
    t_rb_node *node = (t_rb_node*)malloc(sizeof(t_rb_node));

    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->color = black;

    return *node;
}

void rb_insert(t_rb_arbore *a, t_rb_node *z){
    t_rb_node *y = NULL;
    t_rb_node *x = a->root;

    while(x != NULL){
        y = x;
        
        if(z->key = x->key){
            x = x->left;
        }else{
            x = x->right;
        }
    }

    z->parent = y;

    if(y == NULL){
        a->root = z;
    }else if(z->key < y->key){
        y->left = z;
    }else{
        y->right = z;
    }

    z->left = NULL;
    z->right = NULL;
    z->color = red;

    // rb_insert_fixup(a, z);
}

void inorder_walk(t_rb_node *root){
    if(root != NULL){
        inorder_walk(root->left);

        printf("%d", root->key);

        if(root->color == black){
            printf("[b]");
        }else{
            printf("[r]");
        }

        inorder_walk(root->right);
    }
}

t_rb_node tree_search(t_rb_node *n, int key){
    if(n == NULL || key == n->key){
        return *n;
    }

    if(key < n->key){
        return tree_search(n->left, key);
    }else{
        return tree_search(n->right, key);
    }
}


void left_rotate(t_rb_arbore *a, t_rb_node *x){
    t_rb_node *y;
    y = x->right;
    x->right = y->left;

    if(y->left != NULL){
        y->left->parent = x;
    }

    y->parent = x->parent;

    if(x->parent == NULL){
        a->root = y;
    }else if(x == x->parent->left){
        x->parent->left = y;
    }else{
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

void right_rotate(t_rb_arbore *a, t_rb_node *x){
    t_rb_node *y;
    y = x->left;
    x->left = y->right;

    if(y->right != NULL){
        y->right->parent = x;
    }

    y->parent = x->parent;

    if(x->parent == NULL){
        a->root = y;
    }else if(x == x->parent->right){
        x->parent->right = y;
    }else{
        x->parent->left = y;
    }

    y->right = x;
    x->parent = y;
}

// start implementing fixup
void rb_insert_fixup(t_rb_arbore *a, t_rb_node *z){
    t_rb_node *y;
    while(z->parent != NULL && z->parent->color == red){
        if(z->parent == z->parent->parent->left){
            y = z->parent->parent->right;
            
            if(y != NULL && y->color == red){
                z->parent->color = black;
                y->color = black;
                z->parent->parent->color = red;
                z = z->parent->parent;
            }else if(z == z->parent->right){
                z = z->parent;
                left_rotate(a, z);
            }

            z->parent->color = black;
            z->parent->parent->color = red;
            right_rotate(a, z->parent->parent);
        }else{
            y = z->parent->parent->left;
            if(y != NULL && y->color == red){
                z->parent->color = black;
                y->color = black;
                z->parent->parent->color = red;
                z = z->parent->parent;
            }else if(z == z->parent->left){
                z = z->parent;
                right_rotate(a, z);
            }

            z->parent->color = black;
            z->parent->parent->color = red;
            left_rotate(a, z->parent->parent);
        }
    }
}
