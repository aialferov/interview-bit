typedef struct Queue Queue;

Queue* queue_new();
void queue_delete(Queue*);
void queue_push(Queue*, void*);
void queue_pop(Queue*);
int queue_empty(Queue*);
void* queue_head(Queue*);
void* queue_take(Queue*);
