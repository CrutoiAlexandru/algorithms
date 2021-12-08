#include "array_sort.h"

extern int heap_size;

int partition(int a[], int p, int r){
    int x = a[r];
    int i = p - 1;
    int j, aux;

    for(j = p; j <= r - 1; j++){
        if(a[j] <= x){
            i++;

            aux  = a[i];
            a[i] = a[j];
            a[j] = aux; 
        }
    }

    a[r] = a[i + 1];
    a[i + 1] = x;

    return i + 1;
}

void quick_sort(int a[], int p, int r){
    int q = 0;

    if(p < r){
        q = partition(a, p, r);
        quick_sort(a, p, q - 1);
        quick_sort(a, q + 1, r);
    }
}

int left(int x){
    return 2 * x;
}

int right(int x){
    return 2 * x + 1;
}

void max_heapify(int a[], int x){
    int l = left(x);
    int r = right(x);
    int largest, aux;

    if(l <= heap_size && a[l] > a[x]){
        largest = l;
    }else{
        largest = x;
    }

    if(r <= heap_size && a[r] > a[largest]){
        largest = r;
    }

    if(largest != x){
        aux  = a[x];
        a[x] = a[largest];
        a[largest] = aux;

        max_heapify(a, largest);
    }
}

void build_max_heap(int a[], int n){
    heap_size = n;
    int i;

    for(i = n / 2; i > 1; i--){
        max_heapify(a, i);
    } 
}

void heap_sort(int a[], int n){
    int i, aux;

    build_max_heap(a, n);

    for(i = n; i > 2; i--){
        aux = a[1];
        a[1] = a[i];
        a[i] = aux;

        heap_size = heap_size - 1;
        max_heapify(a, 1);
    }
}