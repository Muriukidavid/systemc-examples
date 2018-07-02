/*
 * decoder_2by4.h
 *
 *  Created on: Mar 4, 2016
 *      Author: karibe
 */

#ifndef DECODER_1BY2_H_
#define DECODER_1BY2_H_
#include<systemc.h>
#include"inverter.h"

SC_MODULE(decoder){
//input and output ports
sc_in<bool> a;
sc_out<bool> b,c;
inverter *invgate;

//constructor: where the processes are bound to simulation kernel
SC_CTOR(decoder){
	invgate = new inverter("inverter_gate_instance_1");
	invgate->inv_x(a);
	invgate->inv_y(b);
	invgate->inv_z(c);
	//SC_METHOD(decode);
	//SC_METHOD(decode1by2details);
	sensitive<<a;
	//dont_initialize();
}

~decoder(){
//delete stuff :P
}

void decode(void){
	b=(a==0)?1:0;
	c=(a==1)?1:0;
}

void decode1by2details(void){
}
};




#endif /* DECODER_2BY4_H_ */
