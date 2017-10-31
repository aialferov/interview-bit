typedef struct Queue Queue;

Queue* queue_new();
void queue_push(Queue*, void*);
void queue_pop(Queue*);
void* queue_head(Queue*);
void* queue_take(Queue*);
