#include<stdio.h>

//aflam nr max de coloane (ineficient)
int funcNrColoane(int nrLinii){
    int max = 1;

    for(int i = 0; i < nrLinii; i++){
        max = max + 2;
    }

    return max;
}

int main(){
    //declaram variabilele
    int nrLinii, nrColoane, piramida[100][100], nrCaractere;

    scanf("%d", &nrLinii);

    nrColoane = funcNrColoane(nrLinii); // nrLinii * 2 + 1

    //parcurgem matricea
    for(int i = 0; i < nrLinii; i++){
        //calculam nr de caractere necesar fiecarei linii
        nrCaractere = (i + 1) * 2 + 1; // funcNrColoane(i + 1)

        //printam nr necesar de spatii pe fiecare linie
        for(int j = 0; j < nrColoane; j++){
            if(j < nrLinii - (i + 1)){
                printf(" ");
            }
        }

        //printam primul slash
        printf("/");

        //printam *
        for(int k = 0; k < nrCaractere - 2; k++){
            printf("*");
        }

        //printam al doilea slash
        printf("\\");
        printf("\n");
    }
}