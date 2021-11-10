#ifndef __commands
#define __commands

typedef struct rb_node{
    enum {red, black} color;
    int key;
    struct rb_node *left, *right, *parent;
}t_rb_node;

typedef struct{
    t_rb_node *root;
}t_rb_arbore;

t_rb_node make_root(t_rb_arbore *a, int key);
t_rb_node create_node(int key);
void rb_insert(t_rb_arbore *a, t_rb_node *z);
void inorder_walk(t_rb_node *root);
t_rb_node tree_search(t_rb_node *n, int key);

#endif