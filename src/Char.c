
#include <stdio.h>
#include <stdlib.h>
#include "Char.h"

Char new_Char (char c) {
    
    Char this = (Char) malloc ( sizeof(struct Char) );
    
    if(this == NULL){
        perror("\n\n ***** A Terminating Error Ocurred ***** \n\n");
        exit(1);
    }
    
    this->c = c;
    this->next = NULL;
    
    return this;
    
}
