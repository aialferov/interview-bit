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
    *An = node_count(T);
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
    *An = node_count(T);
    int i = 0, *A = (int*)malloc(*An*sizeof(int));

    Stack *stack = stack_new();
    stack_push(stack, T);
    while(!stack_empty(stack)) {
        BstNode *node = stack_take(stack);
        if (node->right) stack_push(stack, node->right);
        if (node->left) stack_push(stack, node->left);
        A[i++] = node->data;
    }

    return A;
}

int* traversal_postorder(BstNode *T, int *An) {
    *An = node_count(T);
    int i = 0, *A = (int*)malloc(*An*sizeof(int));

    Stack *stack = stack_new();
    stack_push(stack, T);
    while(!stack_empty(stack)) {
        BstNode *node = stack_take(stack);
        if (node->left) stack_push(stack, node->left);
        if (node->right) stack_push(stack, node->right);
        A[i++] = node->data;
    }

    return A;
}

int main() {
    int A[] = {1,2,3,4,5,6,7,8,9};
    BstNode *T = bst_from_array(A, sizeof(A)/sizeof(int));
    bst_print(T);

    int *At, An;

    At = traversal_level_order(T, &An);
    array_print(At, An);
    free(At);

    At = traversal_preorder(T, &An);
    array_print(At, An);
    free(At);

    At = traversal_postorder(T, &An);
    array_print(At, An);
    free(At);

    bst_delete(T);
}
