#include "cut_rod.h"

int main(){
    int n, i, maxvalue;
    int a[100];

    scanf("%d", &n);

    read_prices(a, n);

    maxvalue = cut_rod(a, n);
    printf("%d", maxvalue);

    maxvalue = memoized_cut_rod(a, n);
    printf("%d", maxvalue);

    maxvalue = bottom_up_cut_rod(a, n);
    printf("%d", maxvalue);
}