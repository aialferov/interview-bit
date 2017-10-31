typedef struct ListItem ListItem;
struct ListItem {
    int data;
    ListItem *next;
};

ListItem* new_list(int);
ListItem* new_list_item(int, ListItem*);

void print_list(ListItem*);
