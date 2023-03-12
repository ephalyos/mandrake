
struct Node {
    struct Node * prev;
    struct Node * next;
    void * data;
};

typedef struct Node * Node;

Node new_Node ( void * data ) ;
