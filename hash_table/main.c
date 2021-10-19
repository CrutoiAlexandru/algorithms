#include "hash_table/hash_table.h"

int main(){  
    int hash_table[100];
    int size, key, key_slot;

    printf("Lungime tabela: ");   scanf("%d", &size);

    HASH_INIT(hash_table, size);

    printf("Dati numere pana la citirea lui 0\n");

    scanf("%d", &key);

    while(key != 0){
        key_slot = HASH_INSERT(hash_table, key, size);

        printf("Cheia inserata la locatia: %d\n", key_slot);
        scanf("%d", &key);
    }

    HASH_PRINT(hash_table, size);

    search:
    printf("Cautare cheie: ");
    scanf("%d", &key);

    key_slot = HASH_SEARCH(hash_table, key, size);

    if(key_slot > -1){
        printf("Cheie gasita la locatia: %d\n", key_slot);
    }else{
        printf("Cheia nu a fost gasita\n");
    }

    //looping searching mechanic
    if(key != 0){
        goto search;
    }

    delete:
    printf("Stergere cheie: ");
    scanf("%d", &key);

    key_slot = HASH_DELETE(hash_table, key, size);

    if(key_slot > -1){
        printf("Cheie stearsa la locatia: %d\n", key_slot);
        
        HASH_PRINT(hash_table, size);
    }else{
        printf("Cheia nu a fost stearsa!");
    }

    //looping deleting mechanic
    if(key != 0){
        goto delete;
    }
}