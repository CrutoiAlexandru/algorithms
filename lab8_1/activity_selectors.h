#ifndef __activity_selectors
#define __activity_selectors

#include <stdio.h>

int recursive_activity_selector(int s[], int f[], int k, int n, int a[]);
int greedy_activity_selector(int s[], int f[], int n, int a[]);
void read_array(int r[], int n);
void print_array(int r[], int n);

#endif