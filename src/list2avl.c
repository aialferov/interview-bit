#include <stdio.h>
#include <stdlib.h>

#include "bst.h"
#include "list.h"

BstNode* add_node(BstNode *node, int data);
BstNode* balance_node(BstNode *node);
BstNode* rotate_left(BstNode *node);
BstNode* rotate_right(BstNode *node);
int height(BstNode *node);

BstNode* list2avl(ListItem *head) {
    BstNode *root = 0;
    while (head) {
        root = add_node(root, head->data);
        head = head->next;
    }
    return root;
}

BstNode* add_node(BstNode *node, int data) {
    if (!node) return new_bst_node(data, 0, 0);

    if (data > node->data)
        node->right = add_node(node->right, data);
    else
        node->left = add_node(node->left, data);

    return balance_node(node);
}
BstNode* balance_node(BstNode *node) {
    int diff = height(node->right) - height(node->left);
    return (diff > 1) ? rotate_left(node) :
           ((diff < -1) ? rotate_right(node) : node);
}
BstNode* rotate_left(BstNode *node) {
    BstNode *child = node->right;
    node->right = child->left;
    child->left = node;
    return child;
}
BstNode* rotate_right(BstNode *node) {
    BstNode *child = node->left;
    node->left = child->right;
    child->right = node;
    return child;
}
int max(int a, int b) {
    return a > b ? a : b;
}
int height(BstNode *node) {
    return !node ? -1 : (1 + max(height(node->right), height(node->left)));
}

int main() {
    ListItem *list = new_list(10);
    print_list(list);
    print_bst(list2avl(list));
    BstNode *node = new_bst_node(1, new_bst_node(2, 0, 0), new_bst_node(3, new_bst_node(4, 0, new_bst_node(5, 0, 0)), 0));
    print_bst(node);
    printf("%d\n", height(node));
}
