#include <stdlib.h>

#include "list.h"

typedef struct Queue Queue;
struct Queue {
    ListItem *head; 
    ListItem *tail; 
};

Queue* queue_new() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->head = 0;
    queue->tail = 0;
    return queue;
}
void queue_delete(Queue *queue) {
    free(queue);
}
void queue_push(Queue *queue, void *data) {
    if (queue->tail) {
        queue->tail->next = list_new_item(data, 0);
        queue->tail = queue->tail->next;
    } else {
        queue->tail = list_new_item(data, 0);
        queue->head = queue->tail;
    }
}
void queue_pop(Queue *queue) {
    if (!queue->head) return;

    ListItem *head = queue->head;
    queue->head = queue->head->next;
    if (!queue->head)
        queue->tail = queue->head;

    list_delete_item(head);
}
void* queue_head(Queue *queue) {
    return queue->head ? queue->head->data : 0;
}
void* queue_take(Queue *queue) {
    void *data = queue_head(queue);
    queue_pop(queue);
    return data;
}
