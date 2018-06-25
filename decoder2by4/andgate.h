/*
 * decoder_2by4.cc
 *
 *  Created on: May 28, 2018
 *      Author: Stephen
 */

#ifndef ANDGATE_H_
#define ANDGATE_H_
#include <systemc.h>

SC_MODULE(and_gate){
//ports
    sc_in<bool> X, Y;
    sc_out<bool> Z;
//Constructor
    SC_CTOR(and_gate){
        SC_METHOD(a_gate);
        sensitive<<X<<Y;
    }
~and_gate(){
//delete stuff :P
}

    void a_gate(void){
        Z = (X==1&&Y==1)?1:0;
    }
};

#endif /* ANDGATE_H_ */
