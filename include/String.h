
struct String {
    
    Char head;
    Char tail;
    
    unsigned int size;
    
};

typedef struct String * String;

void add_Char (String this, char c) ;

String new_String (const char *str) ;

void print_String (String this) ;

