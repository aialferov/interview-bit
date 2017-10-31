#include <stdio.h>
#include <stdlib.h>

#include "bst.h"
#include "array.h"

BstNode* arr2bst(int *A, int An) {
    return !An ? 0 :
        new_bst_node(A[An/2], arr2bst(A, An/2), arr2bst(A+An/2+1, An/2-1+An%2)); 
}

int main() {
    int A[] = {1,2,3,4,5,6,7,8,9};
    print_array(A, sizeof(A)/sizeof(int));
    print_bst(arr2bst(A, sizeof(A)/sizeof(int)));
    return 0;
}
