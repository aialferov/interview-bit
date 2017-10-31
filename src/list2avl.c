#include <stdio.h>
#include <stdlib.h>

#include "bst.h"
#include "list.h"

typedef struct Data Data;
struct Data { int value; };
void* data_new(int value) {
    Data *data = (Data*)malloc(sizeof(Data));
    data->value = value + 1;
    return data;
}
void print_data(void *data) {
    Data *d = (Data*)data;
    printf("%d ", d->value);
}

BstNode* add_node(BstNode *node, int data);
BstNode* balance_node(BstNode *node);
BstNode* rotate_left(BstNode *node);
BstNode* rotate_right(BstNode *node);
int height(BstNode *node);

BstNode* list2avl(ListItem *head) {
    BstNode *root = 0;
    while (head) {
        Data *data = (Data*)head->data;
        root = add_node(root, data->value);
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
    ListItem *list = list_new(10, data_new);
    list_print(list, print_data);
    print_bst(list2avl(list));
}
