#ifndef INVERTER_H_
#define INVERTER_H_
#include<systemc.h>

SC_MODULE(NOT){
    //input and output ports
    sc_in<bool> not_a;
    sc_out<bool> not_b;
    //constructor: where the processes are bound to simulation kernel
    SC_CTOR(NOT){
        SC_METHOD(invert);
        sensitive<<not_a;
        //dont_initialize();
    }

    ~NOT(){
    //delete stuff :P
    }

    void invert(void){
        not_b=!not_a;
    }
};
#endif /* INVERTER_H_ */
