#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

BstNode* bst_from_array(int *A, int An) {
    return !An ? 0 : bst_new_node(
        A[An/2],
        bst_from_array(A, An/2),
        bst_from_array(A+An/2+1, An/2-1+An%2)
    ); 
}

BstNode* bst_new_node(int data, BstNode *left, BstNode *right) {
    BstNode *node = (BstNode*)malloc(sizeof(BstNode));
    node->data = data;
    node->left = left;
    node->right = right;
    return node;
}
void bst_delete(BstNode *node) {
    if (!node) return;
    if (node->left) bst_delete(node->left);
    if (node->right) bst_delete(node->right);
    free(node);
}
int bst_size(BstNode *node) {
    return !node ? 0 : 1 + bst_size(node->left) + bst_size(node->right);
}
void bst_print_node(BstNode *node) {
    if (!node) return;
    printf("%d ", node->data);
    bst_print_node(node->left);
    bst_print_node(node->right);
}
void bst_print(BstNode *node) {
    bst_print_node(node);
    printf("\n");
}
