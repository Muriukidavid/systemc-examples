/*
 * decoder_2by4.h
 *
 *  Created on: May 30, 2018
 *      Author: Stephen
 */

#ifndef DECODER_2BY4_H_
#define DECODER_2BY4_H_

#include "../decoder1by2/decoder_1by2.h"
#include<systemc.h>
#include "andgate.h"

SC_MODULE(decoder2by4){
//input and output ports
sc_in<bool> a1,a2;
sc_out<bool> b1,b2,b3,b4;
sc_signal<bool>sig1,sig2,sig3,sig4;

//declaring
decoder dec;
decoder dec2;
and_gate gate1;
and_gate gate2;
and_gate gate3;
and_gate gate4;

//constructor: where the processes are bound to simulation kernel
SC_CTOR(decoder2by4):
//instances
dec("decoder_instance1"),
dec2("decoder_instance2"),
gate1("and_gateinstance_1"),
gate2("and_gateinstance_2"),
gate3("and_gateinstance_3"),
gate4("and_gateinstance_4"){

//interconnections b2in modules

//1st decoder
dec.a(a1);
dec.b(sig1);
dec.c(sig2);
//2nd decoder
dec2.a(a2);
dec2.b(sig3);
dec2.c(sig4);
//gate1
gate1.X(sig1);
gate1.Y(sig3);
gate1.Z(b1);
//gate2
gate2.X(sig1);
gate2.Y(sig4);
gate2.Z(b2);

//gate3
gate3.X(sig2);
gate3.Y(sig3);
gate3.Z(b3);

//gate4
gate4.X(sig2);
gate4.Y(sig4);
gate4.Z(b4);

}

~decoder2by4(){
//delete stuff :P
}
};




#endif /* DECODER_2BY4_H_ */
