
#ifndef AUTOMATA_H
#define AUTOMATA_H

#include "Bool.h"
#include "String.h"


// OBJECT DEFINITION * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

struct Delta {
    
    int  q;
    char a;
    int  p;
    
};

typedef struct Delta Delta;


// OBJECT DEFINITION * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

struct AutomataObject {
    
    String_t alphabet;
    
    int  current;
    char symbol;
    
    int * finals;
    int finalsSize;
    
    Delta * rules;
    int rulesSize;
    
};

typedef struct AutomataObject Automata_t;


// CLASS DEFINITION * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

struct AutomataClass {
    
    Automata_t ( * new  )  ( String_t     ) ;
    
    void ( * setInit  )  ( Automata_t * , int   ) ;
    
    void ( * addFinal )  ( Automata_t * , int   ) ;
    
    void ( * addRule  )  ( Automata_t * , Delta ) ;
    
    void ( * print    )  ( Automata_t *         ) ;
    
    Bool ( * evaluate )  ( Automata_t * , char  ) ;
    
    void ( * free )  ( Automata_t * ) ;
    
};

typedef struct AutomataClass AutomataClass;


// GLOBAL CLASS OBJECT DEFINITION * * * * * * * * * * * * * * * * * * * * * * * * *

extern const AutomataClass Automata;


#endif