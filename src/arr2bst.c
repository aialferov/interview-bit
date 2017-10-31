#include <stdio.h>
#include <stdlib.h>

#include "bst.h"
#include "array.h"

BstNode* arr2bst(int *A, int An) {
    return !An ? 0 :
        bst_new_node(A[An/2], arr2bst(A, An/2), arr2bst(A+An/2+1, An/2-1+An%2)); 
}

int main() {
    int A[] = {1,2,3,4,5,6,7,8,9};
    array_print(A, sizeof(A)/sizeof(int));
    bst_print(arr2bst(A, sizeof(A)/sizeof(int)));
    return 0;
}
