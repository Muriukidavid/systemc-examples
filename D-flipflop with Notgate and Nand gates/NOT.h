#ifndef INVERTER_H_
#define INVERTER_H_
#include<systemc.h>

SC_MODULE(NOT){
    
    sc_in<bool> not_a;
    sc_out<bool> not_b;
    
    SC_CTOR(NOT){
        SC_METHOD(invert);
        sensitive<<not_a;
        
    }

    ~NOT(){
    
    }

    void invert(void){
        not_b=!not_a;
    }
};
#endif /* INVERTER_H_ */
