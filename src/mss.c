#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}
int mss(int A[], int n) {
    int i, Cur = 0, Max = A[0];
    for (i=1; i<n; ++i) {
        if (A[i] >= 0) { if (Max < 0) Max = A[i]; else Max += A[i]; }
        else Max = max(A[i], Max);
        // Cur = max(A[i], Cur + A[i]);
        //Max = A[i] > 0 ? max(Cur, Max);
    }
    return Max;
}

int main() {
    int A[] = {2,-1,2,3,4,-5};
    printf("%d\n", mss(A, sizeof(A)/sizeof(int)));
}
