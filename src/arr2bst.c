#include "bst.h"
#include "array.h"

int main() {
    int A[] = {1,2,3,4,5,6,7,8,9};
    array_print(A, sizeof(A)/sizeof(int));
    bst_print(bst_from_array(A, sizeof(A)/sizeof(int)));
    return 0;
}
