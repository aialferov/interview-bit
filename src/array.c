#include <stdio.h>

void print_array(int *A, int An) {
    for (int i=0; i<An; ++i) printf("%d ", A[i]);
    printf("\n");
}
