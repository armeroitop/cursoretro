extern "C" {    
    #include "tinyPTC/tinyptc.h"
}

void funcion1(int& a){a--;};
void funcion1(float& a){a++;};

int maint (){
    return 0;
}