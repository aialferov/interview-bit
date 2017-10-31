typedef struct BstNode BstNode;
struct BstNode {
    int data;
    BstNode *left;
    BstNode *right;
};

BstNode* bst_from_array(int*, int);
BstNode* bst_new_node(int, BstNode*, BstNode*);
void bst_delete(BstNode*);
void bst_print(BstNode*);
