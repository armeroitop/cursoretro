extern "C" {    
    #include "tinyPTC/tinyptc.h"
}

void funcion1(int& a){a--;};
void funcion1(float& a){a++;};

int maint (){
    ptc_open("windows", 640, 360);
    for(;;);

    ptc_close();

    return 0;
}