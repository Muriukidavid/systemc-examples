/*
 * decoder_2by4.h
 *
 *  Created on: June 18 2018
 *      Author: Lundih
 */

#ifndef INVERTER_H_
#define INVERTER_H_
#include<systemc.h>

SC_MODULE(notgate){
    //input and output ports
    sc_in<bool> d;
    sc_out<bool> f;
    //constructor: where the processes are bound to simulation kernel
    SC_CTOR(notgate){
        SC_METHOD(invert);
        sensitive<<d;
        //dont_initialize();
    }

    ~notgate(){
    //delete stuff :P
    }

    void invert(void){
        f=!d;
    }
};
#endif /* INVERTER_H_ */
