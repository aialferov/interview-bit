#include <stdio.h>
#include <stdlib.h>

#include "list.h"

ListItem* list_new(int N, void* (*data_new)(int)) {
    ListItem *head = 0, *item = 0;
    for (int i=0; i<N; ++i) {
        if (!head) {
            head = list_new_item(data_new(i), 0);
            item = head;
        } else {
            item->next = list_new_item(data_new(i), 0);
            item = item->next;
        }
    }
    return head;
}
ListItem* list_new_item(void *data, ListItem *next) {
    ListItem *item = (ListItem*)malloc(sizeof(ListItem));
    item->data = data;
    item->next = next;
    return item;
}
void list_delete_item(ListItem *item) {
    free(item);
}
void list_print(ListItem *head, void (*print)(void*)) {
    while(head) {
        print(head->data);
        head = head->next;
    }
    printf("\n");
}
