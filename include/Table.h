
#ifndef INT_TABLE_H
#define INT_TABLE_H


struct TableObject {
    int ** get;
    int rows;
    int cols;
};

typedef struct TableObject Table_t;



struct TableClass {
    
    Table_t ( * new  )  ( unsigned int ) ;
    void    ( * free )  ( Table_t *    ) ;
    
    void    ( * add  )  ( Table_t * , int * ) ;
    
    void    ( * print )  ( Table_t * ) ;
    
};

typedef struct TableClass TableClass;



extern const TableClass Table;



#endif