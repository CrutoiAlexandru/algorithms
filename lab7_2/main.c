#include "bottom_up.h"

int main(){
    int n;
    int a[100];

    scanf("%d", &n);

    read_array(a, n);

    matrix_chain_order(a, n);

    print_optimal_parents(1, n - 1);
}