

#include <stdio.h>
#include <stdlib.h>

#include "Automata.h"
#include "Bool.h"
#include "String.h"


// *******************************************************************************


Automata_t Automata_New ( String_t alphabet ) {
    
    Automata_t * this = (Automata_t *) malloc ( sizeof(Automata_t) );
    
    this->current  = -1;
    this->symbol   = -1;
    
    this->finals     = NULL;
    this->finalsSize = 0;
    
    this->rules     = NULL;
    this->rulesSize = 0;
    
    this->alphabet = alphabet;
    
    return *this;
    
}


// *******************************************************************************


void Automata_Free ( Automata_t * this ) {
    
    free(this->finals);
    free(this->rules);
    
}


// *******************************************************************************


void Automata_Set_Init ( Automata_t * this , int initial ) {
    
    this->current = initial;
    
}


// *******************************************************************************


void Automata_Add_Final ( Automata_t * this , int final ){
    
    this->finalsSize += 1;
    
    this->finals = (int *) realloc (this->finals, sizeof(int) * this->finalsSize);
    
    this->finals[ this->finalsSize - 1 ] = final;
    
}


// *******************************************************************************


void Automata_Add_Rule ( Automata_t * this , Delta rule ) {
    
    this->rulesSize += 1;
    
    this->rules = (Delta *) realloc (this->rules, sizeof(Delta) * this->rulesSize);
    
    this->rules[ this->rulesSize - 1 ] = rule;
    
}


// *******************************************************************************


Bool Automata_Evaluate ( Automata_t * this , char symbol ) {
    
    this->symbol = symbol;
    
    Bool existsTransition = false;
    
    for(int i = 0; i < this->rulesSize; i++){
        
        int q  = this->rules[i].q;
        char a = this->rules[i].a;
        int p  = this->rules[i].p;
        
        if( (this->current == q) && (this->symbol == a) ){
            
            this->current = p;
            
            existsTransition = true;
            
            break;
            
        }
        
    }
    
    return existsTransition;
    
}


// *******************************************************************************


void Automata_Print ( Automata_t * this ){
    
    printf("\n\n    [");
    
    for(int i = 0; i < this->rulesSize; i++){
        
        printf("\n\t    %2d   %2c   %2d", 
            this->rules[i].q, 
            this->rules[i].a,
            this->rules[i].p
        );
        
    }
    
    printf("\n    ] \n\n");
    
}


// ###############################################################################


const AutomataClass Automata = {
    
    .new = Automata_New,
    
    .free = Automata_Free,
    
    .setInit = Automata_Set_Init,
    
    .addFinal = Automata_Add_Final,
    
    .addRule = Automata_Add_Rule,
    
    .evaluate = Automata_Evaluate,
    
    .print = Automata_Print
    
};


// ###############################################################################


