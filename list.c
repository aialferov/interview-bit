#include <stdio.h>
#include <stdlib.h>

#include "list.h"

ListItem* new_list(int N) {
    ListItem *head = 0, *item = 0;
    for (int i=1; i<=9; ++i) {
        if (!head) {
            head = new_list_item(i, 0);
            item = head;
        } else {
            item->next = new_list_item(i, 0);
            item = item->next;
        }
    }
    return head;
}
ListItem* new_list_item(int data, ListItem *next) {
    ListItem *item = (ListItem*)malloc(sizeof(ListItem));
    item->data = data;
    item->next = next;
    return item;
}
void print_list(ListItem *head) {
    while(head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
