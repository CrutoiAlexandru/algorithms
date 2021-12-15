#include "activity_selectors.h"

void print_array(int r[], int n){
    int i;

    for(i = 0; i < n; i++){
        printf("%d", r[i]);
    }
}

void read_array(int r[], int n) {
    int i;

    for(i = 0; i < n; i++){
        scanf("%d", &r[i]);
    }
}

int recursive_activity_selector(int s[], int f[], int k, int n, int a[]) {
    static int na = 0;
    int m = k + 1;

    while(m <= n && s[m] < f[k]) {
        m++;
    }

    if(m <= n) {
        na++;
        a[na] = m;
        recursive_activity_selector(s, f, m, n, a);
    }

    return na;
}

int greedy_activity_selector(int s[], int f[], int n, int a[]) {
    int na = 0;
    int k  = 0;
    int m;

    for(m = 1; m <= n; m++) {
        if(s[m] >= f[k]) {
            na++;
            a[na] = m;
            k = m;
        }
    }

    return na;
}   