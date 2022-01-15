#include <stdio.h>

int main() {
    // n - lungime x, y matrice
    // m - nr militari
    int n, m, aux, i, j;
    int height[1000];
    int matrix[100][100];

    // citire n
    printf("Introduceti n: ");
    scanf("%d", &n);

    // nr militari pt o matrice n linii, n coloane
    m = n * n;

    // citire inaltimi 
    for(i = 0; i < m; i++) {
        printf("Inaltime militar[%d]: ", i + 1);
        scanf("%d", &height[i]);
        printf("\n");
    }

    // sortarea descrescatoare a inaltimilor
    // bubble sort
    for(i = 0; i < m - 1; i++) {
        for(j = i; j < m; j++) {
            if(height[i] < height[j]) {
                aux = height[i];
                height[i] = height[j];
                height[j] = aux;
            }
        }
    }

    // contor pentru scrierea inaltimilor in matrice
    int k = 0;

    // creare matrice cu inaltimi
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            matrix[i][j] = height[k];
            k++;
        }
    } 

    // printare matrice inaltimit
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    } 
}