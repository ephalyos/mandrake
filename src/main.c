
#include "main.h"

int main () {
    
    String_t newString = String.new("New definition");
    
    String.print(&newString);
    
    String.free(&newString);
    
    return 0;
    
}