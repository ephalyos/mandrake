
#include <stdio.h>
#include <stdlib.h>
#include "Char.h"
#include "String.h"

void add_Char (String this, char c) {
    
    Char temp = new_Char(c);
    
    if(this->head == NULL){
        
        if(c != '\0'){
            
            this->head = temp;
            this->tail = temp;
            this->size += 1;
            
        }
        
    } else {
        
        if(c != '\0'){
            
            Char last = this->tail;
            
            last->next = temp;
            
            this->tail = temp;
            
            this->size += 1;
            
        }
        
    }
    
    return;
    
}

String new_String (const char *str) {
    
    String this = (String) malloc ( sizeof(struct String) );
    
    if(this == NULL){
        perror("\n\n ***** A Terminating Error Ocurred ***** \n\n");
        exit(1);
    }
    
    this->head = NULL;
    this->tail = NULL;
    this->size = 0;
    
    while(1){
        
        add_Char(this, *str);
        
        if(*str == '\0'){
            
            break;
            
        }
        
        str++;
        
    }
    
    return this;
    
}

void print_String (String this) {
    
    if(this->head == NULL){
        
        perror("\n ***** This String is Empty ***** \n");
        
    } else {
        
        Char current = this->head;
        
        while(1){
            
            putchar(current->c);
            
            if(current->next == NULL){
                
                putchar('\n');
                
                break;
                
            }
            
            current = current->next;
            
        }
        
    }
    
}
