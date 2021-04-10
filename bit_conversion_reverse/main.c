#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main(){
    int binar[32];
    int exponent = 0;
    int pi = 0;
    double pz = 0;
    int counter = 1, counter1 = 0;
    double sum;

    for(int i = 0; i < 32; i++){
        scanf("%d", &binar[i]);
    }

    int k = 0;

    for(int i = 8; i > 0; i--){
        exponent = (binar[i])*pow(2, k) + exponent;
        k++;
    }

    exponent = exponent - 127;

    for(int i = 9 + exponent; i < 32; i++){
        pz = binar[i]* pow(2, -counter) + pz;
        counter++;
    }

    for(int i = 9 + exponent - 1; i > 8 ; i--){
        pi = binar[i]*pow(2, counter1) + pi;
        counter1++;
    }

    if(pi == 0){
        pz = pz + pow(2, -1);
    }

    pi = pi + pow(2, exponent);

    sum = pi + pz;

    if(binar[0] == 1){
        sum = -sum;
    }

    printf("%f", sum);
}