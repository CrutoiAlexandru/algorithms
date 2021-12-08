#include <stdio.h>
#include <stdlib.h>
#include "headers/array_io.h"
#include "headers/array_sort.h"

extern int heap_size;

int main(){
    int a[10], n;
    heap_size = 0;

    printf("n = "); scanf("%d", &n);

    read_array(a, n);

    printf("Meniu\n");
    printf("1 - sortare prin quicksort\n");
    printf("2 - sortare prin heap sort\n");
    printf("x - pentru iesire\n");

    char choice;
    
    while(choice != 'x'){
        printf("Introduceti optiunea: "); scanf("%c", &choice);

        switch(choice){
            case '1':
                quick_sort(a, 1, n);
                print_array(a, n);
                printf("\n");
                break;
            
            case '2':
                heap_sort(a, n);
                print_array(a, n);
                printf("\n");
                break;
        }
    }

    return 0;
}