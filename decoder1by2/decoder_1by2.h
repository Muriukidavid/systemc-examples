/*
 * decoder_2by4.h
 *
 *  Created on: Mar 4, 2016
 *      Author: karibe
 */

#ifndef DECODER_1BY2_H_
#define DECODER_1BY2_H_
#include"notGate.h"
#include<systemc.h>

	SC_MODULE(decoder){
	//input and output ports
	sc_in<bool> a;
	sc_out<bool> b,c;

	notgate notgt_1;

	//constructor: where the processes are bound to simulation kernel

	SC_CTOR(decoder):notgt_1("notgate_instance_1"){
	//sig1
	notgt_1.o(a);
	//sig2
	notgt_1.p(b);

	SC_METHOD(decode);
	sensitive<<a;
	//dont_initialize();
	}

	~decoder(){
	//delete stuff :P
	}

void decode(void){
	c = a;
}

};


#endif /* DECODER_2BY4_H_ */
