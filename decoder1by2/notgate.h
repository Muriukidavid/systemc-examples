/*
 * decoder_2by4.h
 *
 *  Created on: Mar 4, 2016
 *      Author: karibe
 */

#ifndef INVERTER_H_
#define INVERTER_H_
#include<systemc.h>

SC_MODULE(notgate){
    //input and output ports
    sc_in<bool> o;
    sc_out<bool> p;
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
        p=!o;
    }
};
#endif /* INVERTER_H_ */
