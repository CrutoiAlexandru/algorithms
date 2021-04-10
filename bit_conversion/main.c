#include<stdio.h>
#include<math.h>

int mutare = 0;

double binarIntreg(int pi){
    int contor1 = 1;
    double bin1 = 0;

    while(pi){
              bin1 = (pi%2) * contor1 + bin1;
              contor1 = contor1 * 10;
              pi = pi/2;
              mutare++;
    }

    mutare--;

    return bin1;
}

double binarZecimal(double pz){  
     double contor2 = 1;
     double bin2 = 0;
     int parteIntreagaZ;

     while(pz){
               pz = pz*2;
               parteIntreagaZ = (int)pz;
               bin2 = parteIntreagaZ * contor2 + bin2;
               contor2 = contor2/10;
               pz = pz-parteIntreagaZ;
     }

     return bin2/10;
}

int main(){
    double n, pz, bin2=0, bin1=0;
    int s[32], pi, exponent;
    double Bin;
    
    printf("Programul determina sirul de biti pentru un nr real, simpla precizie, in formatul IEE");
    printf("\n");
    printf("Introduceti numarul:");
    scanf("%lf", &n);
    printf("\n");

    if( n < 0 ){
        s[0] = 1;
    } else {
        s[0] = 0;
    }

    if(n < 0){
        n = -1*n;
    }

    pi = (int)n;

    pz = n-pi;
    
    bin1 = binarIntreg(pi);
    
    bin2 = binarZecimal(pz);

    Bin = bin1 + bin2;

    Bin = Bin/pow(10,mutare);
    
    exponent = binarIntreg(127+mutare);

    for(int i = 8; i > 0; i--){
        s[i] = exponent%10;
        exponent = exponent/10;
    } 

    for(int k = 9; k < 32; k++){
        if(k < 17){
            Bin = Bin - (int)Bin;

            if(Bin*10 >= 1.2){
                Bin = Bin - 1.0;
                Bin = Bin * 10;
                s[k] = (int)Bin;
            }else{
                Bin = Bin * 10;
                s[k] = (int)Bin;
            }
        }else{
            s[k] = 0;
        }
    }     

    for( int i = 0; i < 32; i++){
         printf("%d",s[i]);
    }

    return 0; 
}