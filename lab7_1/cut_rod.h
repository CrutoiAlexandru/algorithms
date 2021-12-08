#ifndef __cut_rod
#define __cut_rod

#include <stdio.h>
#include <limits.h>

int cut_rod(int p[], int n);
void read_prices(int a[], int n);
int bottom_up_cut_rod(int p[], int n);
int memoized_cut_rod(int p[], int n);

#endif