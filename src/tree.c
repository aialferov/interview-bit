#include <stdio.h>

#include "bst.h"

BstNode* flatten(BstNode* T) {
    if (!T) return 0;

    BstNode *Temp = T->right;
    T->right = flatten(T->left);
    T->left = 0;

    BstNode *R = T;
    while (T->right) T = T->right;
    T->right = flatten(Temp);

    return R;
}

int main() {
    int A[] = {1,2,3,4,5,6,7,8,9};
    BstNode *T = bst_from_array(A, sizeof(A)/sizeof(int));

    printf("BST: ");
    bst_print(T);

    printf("BST flatten: ");
    T = flatten(T);
    bst_print(T);
}
