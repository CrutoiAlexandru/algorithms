#include<stdio.h>

void main() {
    int vector[100], vSize , vSize2, memory, i, j, k;

    scanf("%d", &vSize);

    for(i = 0; i < vSize; i ++){
        scanf("%d", &vector[i]);
    }

    for(i = 0; i < vSize; i ++){
        memory = vector[i];

        if(i == vSize - 1){
            if(memory == vector[i+1]){
                vSize2 = vSize - 1;
            }
        }
n
        // for(j = i + 1; j < vSize; j ++){
        //     if(memory == vector[j]){
        //         for(k = j; j < vSize - 1; k ++){
        //             vector[k] = vector[k+1];
        //         }
        //         vSize--;
        //     }
        // }
    }

    for(i = 0; i < vSize2; i++){
        printf("%d, ", vector[i]);
    }
}