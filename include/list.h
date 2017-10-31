typedef struct ListItem ListItem;
struct ListItem {
    void *data;
    ListItem *next;
};

ListItem* list_new(int, void* (*)(int));
ListItem* list_new_item(void*, ListItem*);
void list_delete_item(ListItem*);

void list_print(ListItem*, void (*)(void*));
