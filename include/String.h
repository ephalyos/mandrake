
#ifndef STRING_H
#define STRING_H

#include "Bool.h"

struct StringObject{
    int size ;
    char *str ;
};

typedef struct StringObject String_t;



struct StringClass {
    
    String_t ( * new  )  ( const char * ) ;
    void     ( * free )  ( String_t *   ) ;
    
    char ( * charAt )  ( String_t * , unsigned int ) ;
    Bool ( * charIn )  ( String_t * , char         ) ;
    void ( * print  )  ( String_t *                ) ;
    
    int  ( * size   )  ( String_t *                ) ;
    
};

typedef struct StringClass StringClass;



extern const StringClass String;



#endif