typedef struct BstNode BstNode;
struct BstNode {
    int data;
    BstNode *left;
    BstNode *right;
};

BstNode* bst_new_node(int, BstNode*, BstNode*);
void bst_print(BstNode*);
