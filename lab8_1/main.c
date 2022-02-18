#include "activity_selectors.h"

int main(){
    int sol_rec[100], sol_iter[100], s[100], f[100];
    int n, length_sol_it, length_sol_rec;

    printf("cititi n: ");
    scanf("%d", &n);
    
    printf("cititi sirul s: ");
    read_array(s, n);
    printf("cititi sirul f: ");
    read_array(f, n);

    f[0] = 0;

    length_sol_rec = recursive_activity_selector(s, f, 0, n, sol_rec);

    printf("Solutie recursiva: ");
    print_array(sol_rec, length_sol_rec);

    length_sol_it = greedy_activity_selector(s, f, n, sol_iter);

    printf("Solutie iterativa: ");
    print_array(sol_iter, length_sol_it);
}