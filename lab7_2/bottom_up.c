#include "bottom_up.h"

extern int s[100][100];

void read_array(int a[], int n){
    int i;

    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
}

void print_optimal_parents(int i, int j){
    if(i == j){
        printf("A"); printf("%d", i);
    }else{
        printf("(");
        print_optimal_parents(i, s[i][j]);
        print_optimal_parents(s[i][j] + 1, j);
        printf(")");
    }
}

void matrix_chain_order(int p[], int n){
    int i, j, k, t, q;
    
    n = n - 1;

    int m[n][n];

    for(i = 1; i <= n; i++){
        m[i][i] = 0;
    }

    for(t = 2; t <= n; t++){
        for(i = 1; i <= n - t + 1; i++){
            j = i + t - 1;

            m[i][j] = INT_MAX;

            for(k = i; k <= j - 1; k++){
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}