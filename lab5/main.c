#include <stdio.h>
#include <stdlib.h>
#include "headers/array_io.h"
#include "headers/array_sort.h"

int main(){
    int a[10], n;

    printf("n = "); scanf("%d", &n);

    read_array(a, n);

    printf("Meniu\n");
    printf("1 - sortare prin insertie\n");
    printf("2 - sortare prin merge sort\n");
    printf("x - pentru iesire\n");

    char choice;
    
    while(choice != 'x'){
        printf("Introduceti optiunea: "); scanf("%c", &choice);

        switch(choice){
            case '1':
                insertion_sort(a, n);
                print_array(a, n);
                printf("\n");
                break;
            
            case '2':
                merge_sort(a, 1, n);
                print_array(a, n);
                printf("\n");
                break;
        }
    }

    return 0;
}