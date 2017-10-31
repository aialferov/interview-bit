#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

BstNode* new_bst_node(int data, BstNode *left, BstNode *right) {
    BstNode *node = (BstNode*)malloc(sizeof(BstNode));
    node->data = data;
    node->left = left;
    node->right = right;
    return node;
}
void print_bst_node(BstNode *node) {
    if (!node) return;
    printf("%d ", node->data);
    print_bst_node(node->left);
    print_bst_node(node->right);
}
void print_bst(BstNode *node) {
    print_bst_node(node);
    printf("\n");
}
