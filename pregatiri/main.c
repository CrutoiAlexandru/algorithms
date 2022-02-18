#include "calculator/calculator.h"
#include <stdio.h>

int main() {
    int a, b;
    int *c;
    
    printf("valoarea lui a: ");
    scanf("%d", &a);

    printf("valoarea lui b: ");
    scanf("%d", &b);

    suma(a, b, &c);

    printf("%d", *c);

    // for(int i = 0; i < 9; i++) {
    //     printf("%d", a);
    // }

    // printf("\n");

    // int i = 0;

    // while(i < 9) {
    //     if(i == 5) {
    //         break;
    //     }

    //     printf("%d", a);
    //     i++;
    // }

    // printf("\n");

    // do { 
    //     printf("%d", a);
    //     i++;
    // } while(i < 9);

    // printf("%d", i);
    
    // c = suma(a, b);

    // printf("%d", c);

    // printf("%d", inmultire(a, b));

    // return 0;
}