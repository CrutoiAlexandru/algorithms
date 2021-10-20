#ifndef __hash_table
#define __hash_table

#include <stdio.h>
#include <stdlib.h>

void HASH_INIT(int T[], int size);
int  HASH_INSERT(int T[], int key, int size);
int  HASH_PROBEF(int key, int i, int size);
int  HASH_PRIM(int key, int size);
void HASH_PRINT(int T[], int size);
int  HASH_SEARCH(int T[], int key, int size);
int  HASH_DELETE(int T[], int key, int size);

#endif