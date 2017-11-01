#include <stdio.h>
#include <stdlib.h>

#include "bst.h"
#include "array.h"
#include "queue.h"
#include "stack.h"

int node_count(BstNode *T) {
    int N = 0;
    Queue *queue = queue_new();
    queue_push(queue, T);
    while(!queue_empty(queue)) {
        BstNode *node = queue_take(queue);
        if (node->left) queue_push(queue, node->left);
        if (node->right) queue_push(queue, node->right);
        N++;
    }
    queue_delete(queue);
    return N;
}

int* traversal_level_order(BstNode *T, int *An) {
    *An = bst_size(T);
    int i = 0, *A = (int*)malloc(*An*sizeof(int));

    Queue *queue = queue_new();
    queue_push(queue, T);
    while(!queue_empty(queue)) {
        BstNode *node = queue_take(queue);
        if (node->left) queue_push(queue, node->left);
        if (node->right) queue_push(queue, node->right);
        A[i++] = node->data;
    }

    queue_delete(queue);
    return A;
}

int* traversal_preorder(BstNode *T, int *An) {
    *An = bst_size(T);
    int i = 0, *A = (int*)malloc(*An*sizeof(int));

    Stack *stack = stack_new();
    stack_push(stack, T);
    while(!stack_empty(stack)) {
        BstNode *node = stack_take(stack);
        if (node->right) stack_push(stack, node->right);
        if (node->left) stack_push(stack, node->left);
        A[i++] = node->data;
    }
    stack_delete(stack);

    return A;
}

void traversal_inorder1(BstNode*, int*, int*);
int* traversal_inorder(BstNode *T, int *An) {
    *An = bst_size(T);
    int i = 0, *A = (int*)malloc(*An*sizeof(int));

    if (T->left) traversal_inorder1(T->left, A, &i);
    A[i++] = T->data;
    if (T->right) traversal_inorder1(T->right, A, &i);

    return A;
}
void traversal_inorder1(BstNode *T, int *A, int *Ai) {
    Stack *stack = stack_new();
    stack_push(stack, T);
    while(!stack_empty(stack)) {
        BstNode *node = stack_take(stack);
        if (node->right) stack_push(stack, node->right);
        stack_push(stack, node);
        if (node->left) stack_push(stack, node->left);
        if (!node->left && !node->right) {
            while(!stack_empty(stack)) {
                BstNode *node = stack_take(stack);
                A[*Ai] = node->data;
                *Ai = *Ai + 1;
            }
        }
    }
    stack_delete(stack);
}

void traversal_postorder1(BstNode*, int*, int*);
int* traversal_postorder(BstNode *T, int *An) {
    *An = bst_size(T);
    int i = 0, *A = (int*)malloc(*An*sizeof(int));

    if (T->left) traversal_postorder1(T->left, A, &i);
    if (T->right) traversal_postorder1(T->right, A, &i);
    A[i] = T->data;

    return A;
}
void traversal_postorder1(BstNode *T, int *A, int *Ai) {
    Stack *stack = stack_new();
    stack_push(stack, T);
    while(!stack_empty(stack)) {
        BstNode *node = stack_head(stack);
        if (node->right) stack_push(stack, node->right);
        if (node->left) stack_push(stack, node->left);
        if (!node->left && !node->right) {
            while(!stack_empty(stack)) {
                BstNode *node = stack_take(stack);
                A[*Ai] = node->data;
                *Ai = *Ai + 1;
            }
        }
    }
    stack_delete(stack);
}

void traversal_depth_order(BstNode *T) {
    if (!T) return;
    traversal_depth_order(T->left);
    printf("%d ", T->data); // move this line up or down
                            // to get pre- or postorder accordingly
    traversal_depth_order(T->right);
}

int main() {
    int A[] = {1,2,3,4,5,6,7,8,9};
    BstNode *T = bst_from_array(A, sizeof(A)/sizeof(int));

    printf("BST: ");
    bst_print(T);

    int *At, An;

    At = traversal_level_order(T, &An);
    printf("Level order: ");
    array_print(At, An);
    free(At);

    At = traversal_preorder(T, &An);
    printf("Preorder: ");
    array_print(At, An);
    free(At);

    At = traversal_inorder(T, &An);
    printf("Inorder: ");
    array_print(At, An);
    free(At);

    At = traversal_postorder(T, &An);
    printf("Postorder: ");
    array_print(At, An);
    free(At);

    printf("Depth order: ");
    traversal_depth_order(T);
    printf("\n");

    bst_delete(T);
}
