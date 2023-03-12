
#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
#include "List.h"

void nullcheck(void * data){
    if(data == NULL){
        perror("\n\n * * * * * A Terminating Error Ocurred * * * * * \n\n");
        exit(1);
    }
}

List new_List( void * data, void (*print)(void * data) ) {
    
    List this = (List)malloc(sizeof(struct List));
    nullcheck(this);
    
    if(data == NULL){
        
        this->head = NULL;
        this->tail = NULL;
        this->range = 0;
        
    } else {
        
        Node init = new_Node(data);
        nullcheck(init);
        
        this->head = init;
        this->tail = init;
        this->range = 1;
        
    }
    
    this->print_Node = print;
    
    return this;
}



void add_Node (List this, void * data) {
    
    if(data == NULL){
        perror("\n ***** No Data to Add ***** \n");
        return;
    }
    
    Node temp = new_Node(data);
    nullcheck(temp);
    
    if(this->head == NULL){
        
        this->head = temp;
        this->tail = temp;
        this->range = 1;
        
    } else {
        
        Node last = this->tail;
        
        last->next = temp;
        temp->prev = last;
        
        this->tail = temp;
        this->range += 1;
        
    }
    
}

void * get_Node (List this, unsigned int index) {
    
    if(this->head == NULL){
        perror("\n ***** This List is Empty ***** \n");
        return NULL;   
    }
    
    Node current = this->head;
    
    if((index < this->range) && (index >= 0)){
        
        unsigned int node_Number = 0;
        while(node_Number != index){
            current = current->next;
            node_Number++;
        }
        
    } else {
        perror("\n ***** Index out of range ***** \n");
        return NULL;
    }
    
    return current->data;
}

void print_List (List this) {
    
    if(this->range == 0){
        
        perror("\n ***** This List is Empty ***** \n");
        
    } else if(this->print_Node == NULL){
        
        perror("\n ***** No Print Function Was Found ***** \n");
        
    } else {
        
        unsigned int index = 0;
        
         while(index < this->range){
            this->print_Node(get_Node(this,index));
            printf("\n");
            index++;
        }
        
    }
    
    return;
}
