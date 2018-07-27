#ifndef INVERTER_H_
#define INVERTER_H_
#include<systemc.h>

SC_MODULE(notgate){
    //input and output ports
    sc_in<bool> Nom;
    sc_out<bool>Inv;
    //constructor: where the processes are bound to simulation kernel
    SC_CTOR(notgate){
        SC_METHOD(invert);
        sensitive<<o;
        //dont_initialize();
    }

    ~notgate(){
    //delete stuff :P
    }

    void invert(void){
        Inv=!Nom;
    }
};

