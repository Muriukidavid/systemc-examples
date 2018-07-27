/*
 * decoder_2by4.h
 *
 *  Created on: Mar 4, 2016
 *      Author: karibe
 */

#ifndef DECODER_1BY2_H_
#define DECODER_1BY2_H_
#include "notgate.h"
#include<systemc.h>

SC_MODULE(decoder){
	//input and output ports
	sc_in<bool> a;
	sc_out<bool> b,c;
	sc_signal<bool> sig1, sig2;

	notgate NTGT_1;

	//constructor: where the processes are bound to simulation kernel
	SC_CTOR(decoder):notgt_1("Notgate_instance_1"){
		//sig1
		NTGT_1.Nom(a);	
		//sig2
		NTGT_1.Inv(b);
		
		SC_METHOD(decode);
		sensitive<<a;
	}

	~decoder(){
	//delete stuff :P
	}
void decode(void){
	c = a;
}

};
#endif /* DECODER_2BY4_H_ */
