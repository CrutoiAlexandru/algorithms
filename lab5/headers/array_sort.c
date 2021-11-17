#include "array_sort.h"
#include <limits.h>

void insertion_sort(int a[], int n){
    int i, j;
    int key;

    for(j = 2; j <= n; j++){
        key = a[j];
        i = j - 1;

        while(i > 0 && a[i] > key){
            a[i+1] = a[i];
            i = i - 1;
        }

        a[i+1] = key;
    }
}

void merge_sort(int a[], int p, int r){
    int q = 0;

    if(p < r){
        q = (p + r) / 2;

        merge_sort(a, p, q);

        merge_sort(a, q + 1, r);

        merge(a, p, q, r);
    }
}

void merge(int a[], int p, int q, int r){
    int left[10], right[10];
    int n1 = q - p + 1;
    int n2 = r - q;
    int i, j, k;

    for(i = 1; i <= n1; i++){
        left[i] = a[p + i -1];
    }

    for(j = 1; j <= n2; j++){
        right[j] = a[q + j];
    }

    left[n1 + 1] = INT_MAX;
    right[n2 + 1] = INT_MAX;

    i = 1;
    j = 1;

    for(k = p; k <= r; k++){
        if(left[i] <= right[j]){
            a[k] = left[i];
            i++;
        }else{
            a[k] = right[j];
            j++;
        }
    }
}