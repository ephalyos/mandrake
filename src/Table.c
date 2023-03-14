
#include <stdio.h>
#include <stdlib.h>

#include "Table.h"


// *******************************************************************************


Table_t Table_New ( unsigned int cols ) {
    
    Table_t * this = (Table_t *) malloc (sizeof(Table_t));
    
    this->cols = cols;
    this->rows = 0;
    
    return *this;
    
}


// *******************************************************************************


void Table_Free ( Table_t * this ) {
    
    for(int i = 0; i < this->rows; i++){
        
        free(this->get[i]);
        
    }
    
    free(this);
    
}


// *******************************************************************************


void Table_Add_Row ( Table_t * this , int * row ) {
    
    this->rows += 1;
    
    this->get = (int **) realloc ( this->get , sizeof(int *) * this->rows );
    
    this->get[ this->rows - 1 ] = (int *) malloc ( sizeof( int[this->cols] ) );
    
    this->get[ this->rows - 1 ] = row;
    
}


// *******************************************************************************


void Table_Print ( Table_t * this ) {
    
    printf("\n\n    [");
    
    for(int i = 0; i < this->rows; i++){
        
        printf("\n\t");
        
        for(int j = 0; j < this->cols; j++){
            
            printf("%4d  ", this->get[i][j]);
            
        }
        
    }
    
    printf("\n    ] \n");
    
}


// *******************************************************************************



// #####################################################################
// #####################################################################
// #####################################################################



const TableClass Table = {
    
    .new = Table_New,
    
    .free = Table_Free,
    
    .add = Table_Add_Row,
    
    .print = Table_Print
    
};

