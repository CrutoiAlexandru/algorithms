#include "cut_rod.h"

int max(int a, int b){
    if(a < b){
        return b;
    }else{
        return a;
    }
}

int cut_rod(int p[], int n){
    int q, i;

    if(n == 0) {
        return 0;
    }

    q = INT_MIN;

    for(i = 1; i <= n; i++){
        q = max(q, p[i] + cut_rod(p, n - i));
    }

    return q;
}

void read_prices(int a[], int n){
    int i;
    
    for(i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
}

int bottom_up_cut_rod(int p[], int n){
    int j, i, q;
    int r[100];
    r[0] = 0;

    for(j = 1; j <= n; j++){
        q = INT_MIN;

        for(i = 1; i <= j; i++){
            q = max(q, p[i] + r[j - i]);
        }

        r[j] = q;
    }

    return r[n];
}

int memoized_cut_rod_aux(int p[], int n, int r[]){
    int q, i;

    if(r[n] >= 0){
        return r[n];
    }

    if(n == 0){
        q = 0;
    }else{
        q = INT_MIN;
        for(i = 1; i <= n; i++){
            q = max(q, p[i] + memoized_cut_rod_aux(p, n - i, r));
        }
    }

    r[n] = q;

    return q;
}

void print_array(int r[], int n){
    int i;

    for(i = 0; i < n; i++){
        printf("%d", r[i]);
    }
}

int memoized_cut_rod(int p[], int n){
    int q, i;
    int r[100];

    for(i = 0; i < n; i++){
        r[i] = INT_MIN;
    }

    q = memoized_cut_rod_aux(p, n, r);

    print_array(r, n);

    return q;
}