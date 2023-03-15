
#include <stdio.h>
#include <stdlib.h>

#include "Bool.h"
#include "String.h"


// *******************************************************************************


String_t String_New ( const char * str ) {
    
    String_t * this = (String_t *) malloc (sizeof(String_t));
    
    int size = 0;
    
    for(int i = 0; *(str + i) != '\0'; i++){
        size++;
    }
    
    this->size = size;
    
    char * tempStr = (char *) malloc (sizeof(char) * (size + 1));
    
    for(int i = 0; ; i++){
        *(tempStr + i) = *(str + i);
        if(*(str + i) == '\0'){
            break;
        }
    }
    
    this->str = tempStr;
    
    return *this;
    
}


// *******************************************************************************


void String_Free ( String_t * this ) {
    
    free(this->str);
    
}


// *******************************************************************************


char String_Char_At ( String_t * this , unsigned int index ) {
    
    if ( index >= this->size ){
        
        puts("\n\t ERROR: INDEX OUT OF BOUNDS \n");
        
        return 0;
        
    } 
    
    return this->str[index];
    
}


// *******************************************************************************


Bool String_Char_In ( String_t * this , char c ) {
    
    Bool exists = false;
    
    for(int i = 0; i < this->size; i++){
        if(this->str[i] == c){
            exists = true;
            break;
        }
    }
    
    return exists;
    
}


// *******************************************************************************


void String_Print ( String_t * this ) {
    
    puts(this->str);
    
}


// *******************************************************************************


int String_Get_Size ( String_t * this ) {
    
    return this->size;
    
}


// ###############################################################################


const StringClass String = { 

    .new = String_New, 
    
    .free = String_Free, 
    
    .charAt = String_Char_At,
    
    .charIn = String_Char_In,
    
    .print = String_Print,
    
    .size = String_Get_Size
    
};


// ###############################################################################
