#include <stdio.h>
#include <stdlib.h>
#include "lista/lista.h"

char Get_command(void) {
   char c;

   printf("q(Q): quit, i(I): insert first, p(P): print, s(S): search, d(D): delete\n");
   printf("Introduceti o comanda:  ");
   scanf(" %c", &c);
   return c;
}  

int  Get_value(void) {
   int val;

   printf("Introduceti o valoare intreaga:  ");
   scanf("%d", &val);
   return val;
}

int main(){
    t_lista lista;
    t_nod_lista *x;
    char comanda;
    int  val;

	makenull(&lista);
    comanda = Get_command();

    while (comanda != 'q' && comanda != 'Q') {
      switch (comanda) {
         case 'i': 
         case 'I': 
            val = Get_value();
            insert_first_cheie(&lista, val);  
            break;
         case 'p':
         case 'P':
            print(lista);
            break;
         case 's': 
         case 'S':
            val = Get_value();
            if (search(lista, val, &x)) printf("valoare gasita\n");
			else printf("valoarea nu a fost gasita\n");   
            break;
         case 'd':
         case 'D':
            val = Get_value();
            if (delete_cheie(&lista, val)) printf("cheia %d a fost strearsa cu success\n", val);
			else printf("cheia %d nu a fost gasita\n", val);  
            break;
         default:
            printf("comanda %c nu este valida\n", comanda);
            printf("Introduceti o comanda noua\n");
      }
      comanda = Get_command();
   }

    free_mem(&lista);
	return 0;
}