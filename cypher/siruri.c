#include <stdio.h>
#include <string.h>

// CODE LENGTH CAN BE REDUCED IM JUST LAZY

int main() {
    char string1[100], string2[100];
    int aux1[100], aux2[100];
    int test_number = 0;

    // read the strings equal in size
    scanf("%s", &string1);
    scanf("%s", &string2);

    // first string
    for(int i = 0; i < strlen(string1); i++) {
        // initiate the aux1 with value 0
        aux1[i] = 0;   
    }

    for(int i = 0; i < strlen(string1); i++) {
        // check if aux1 place is empty(== 0)
        // if so increment the test_number in order to asign it to a certain character
        if(aux1[i] == 0) test_number++;

        for(int j = i; j < strlen(string1); j++) {
            if(string1[i] == string1[j] && aux1[j] == 0) {
                // if our curent place in the string matches our previous place (place of i == place of j) 
                // we asign the character the test_number
                // this way we can reduce the array from one of characters into one of integers
                aux1[j] = test_number;
            }
        }
    }
    // first string
    
    // reinitiate the test_number to 0 for the second string
    test_number = 0;

    // second string (same steps)
    for(int i = 0; i < strlen(string2); i++) {
        aux2[i] = 0;   
    }

    for(int i = 0; i < strlen(string2); i++) {

        if(aux2[i] == 0) test_number++;

        for(int j = i; j < strlen(string2); j++) {
            if(string2[i] == string2[j] && aux2[j] == 0) {
                aux2[j] = test_number;
            }
        }
    }
    // second string

    // aux display
    for(int i = 0; i < strlen(string1); i++) {
        printf("%d", aux1[i]);
    }

    printf("\n");

    for(int i = 0; i < strlen(string2); i++) {
        printf("%d", aux2[i]);
    }

    printf("\n");
    // aux display

    // if the same spots in both aux are equal it means that our character is repeating
    // this way we can check if the replacement of our character in the first string is unique to the one in our second string
    // if this condition is true untill the end it means our character replacement is unique and the cypher is possible
    // cypher = encoding one character to another (if it makes sens??)
    for(int i = 0; i < strlen(string2); i++) {
        if(aux1[i] != aux2[i]) {
            printf("FALSE");
            return 1;
        }
    }

    printf("TRUE");
    return 0;
}