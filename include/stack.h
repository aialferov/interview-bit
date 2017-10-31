typedef struct Stack Stack;

Stack* stack_new();
void stack_push(Stack*, void*);
void stack_pop(Stack*);
void* stack_head(Stack*);
void* stack_take(Stack*);
