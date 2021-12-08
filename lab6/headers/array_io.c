#include "array_io.h"
#include <stdio.h>

void read_array(int v[], int n){
    int i;

    for(i = 1; i <= n; i++){
        scanf("%d", &v[i]);
    }
}

void print_array(int v[], int n){
    int i;

    for(i = 1; i <= n; i++){
        printf("%d", v[i]);
    }
}