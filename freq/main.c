#include<stdio.h>

int main() {
    int n, v[100], i = 0, z[100];

    scanf("%d", &n);

    while(n) {
        v[i] = n%10;
        n = n/10;
        z[i] = 1;
        i++;
    }

    for(int a = 0; a < i-1; a++){
        for(int b = 1; b < i; b++){
            if(v[a] == v[b]){
                z[a]++;
            } 
        }
    }

    for(int j = 0; j < i; j++){
        printf("%d ", v[j]);
    }
    for(int j = 0; j < i; j++){
        printf("%d ", z[j]);
    }
}