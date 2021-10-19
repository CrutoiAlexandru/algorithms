#include "hash_table.h"

void HASH_INIT(int T[], int size){
    for(int j = 0; j < size; j++){
        T[j] = -1;
    }
}

int HASH_INSERT(int T[], int key, int size){
    int i = 0;
    int j;

    do{
        j = HASH_PROBEF(key, i, size);

        if(T[j] == -1){
            T[j] = key;
            
            return j;
        }else{
            i++;
        }
    }while(i != size);

    return -1;
}

int HASH_PROBEF(int key, int i, int size){
    return (HASH_PRIM(key, size) + i) % size;
}

int HASH_PRIM(int key, int size){
    return key % size;
}

void HASH_PRINT(int T[], int size){
    for(int j = 0; j < size; j++){
        printf("%d  ", T[j]);
    }

    printf("\n");
}

int HASH_SEARCH(int T[], int key, int size){
    int i = 0;
    int j;

    do{
        j = HASH_PROBEF(key, i, size);

        if(T[j] == key){
            return j;
        }

        i++;
    }while(i != size && T[j] != -1);

    return -1;
}

int HASH_DELETE(int T[], int key, int size){
    int j = HASH_SEARCH(T, key, size);

    if(j > -1){
        T[j] = -1;

        return j;
    }else{
        return -1;
    }
}