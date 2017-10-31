typedef struct BstNode BstNode;
struct BstNode {
    int data;
    BstNode *left;
    BstNode *right;
};

BstNode* new_bst_node(int, BstNode*, BstNode*);
void print_bst(BstNode*);
