#include <stdio.h>

void array_print(int *A, int An) {
    for (int i=0; i<An; ++i) printf("%d ", A[i]);
    printf("\n");
}
