#include <stdlib.h>

#include "list.h"

typedef struct Stack Stack;
struct Stack {
	ListItem *head;
};

Stack* stack_new() {
	Stack *stack = (Stack*)malloc(sizeof(Stack));
	stack->head = 0;
	return stack;
}
void stack_push(Stack *stack, void *data) {
	stack->head = list_new_item(data, stack->head);
}
void stack_pop(Stack *stack) {
	if (!stack->head) return;

	ListItem *head = stack->head;
	stack->head = head->next;

	list_delete_item(head);
}
void* stack_head(Stack *stack) {
	return stack->head ? stack->head->data : 0;
}
void* stack_take(Stack *stack) {
	void *data = stack_head(stack);
	stack_pop(stack);
	return data;
}
