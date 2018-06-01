/*
 * decoder_2by4.h
 *
 *  Created on: Mar 4, 2016
 *      Author: karibe
 */

#ifndef DECODER_1BY2_H_
#define DECODER_1BY2_H_
#include"and_gate.h"
#include"inverter.h"
#include<systemc.h>

SC_MODULE(decoder){
//input and output ports
sc_in<bool> a;
sc_out<bool> b,c;
inverter inv;
//constructor: where the processes are bound to simulation kernel
SC_CTOR(decoder):inv("inverter_instance"){	
	//invert signal 'a' and parse it to 'b'
	inv.x(a);
	inv.y(b);

	SC_METHOD(decode);
	sensitive<<a;
	//dont_initialize();
}

~decoder(){
//delete stuff :P
}

void decode(void){
	//b=(a==0)?1:0;											
	c = a;
}
};

#endif /* DECODER_2BY4_H_ */
