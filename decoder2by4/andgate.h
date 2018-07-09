/*
 * decoder_2by4.cc
 *
 *  Created on: May 27, 2018
 *      Author: Bmaake
 */

#ifndef ANDGATE_H_
#define ANDGATE_H_

#include <systemc.h>

SC_MODULE(andgate){
    sc_in<bool> x, y;
    sc_out<bool> z;

    SC_CTOR(andgate){
        SC_METHOD(andgt);
        sensitive<<x<<y;
    }
~andgate(){
//delete stuff :P
}

    void andgt(void){
        z = (x && y);
    }
};

#endif /* ANDGATE_H_ */
