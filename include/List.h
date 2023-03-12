
struct List {
    
    struct Node * head;
    struct Node * tail;
    unsigned int range;
    
    void (*print_Node) (void * data);
    
};

typedef struct List * List;

List new_List( void * data, void (*print)(void * data) ) ;

void add_Node (List this, void * data) ;

void * get_Node (List this, unsigned int index) ;

void print_List (List this) ;
