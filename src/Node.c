
#include <stdlib.h>
# include "Node.h"

Node new_Node ( void * data ) {
    Node this = (Node)malloc(sizeof(struct Node));
    this->prev = NULL;
    this->next = NULL;
    this->data = data;
    return this;
}
