#ifndef __hash_table
#define __hash_table

#include <stdio.h>
#include <stdlib.h>

void HASH_INIT(int[], int);
int  HASH_INSERT(int[], int, int);
int  HASH_PROBEF(int, int, int);
int  HASH_PRIM(int, int);
void HASH_PRINT(int[], int);
int  HASH_SEARCH(int[], int, int);
int  HASH_DELETE(int[], int, int);

#endif