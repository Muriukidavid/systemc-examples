/*
 * decoder_1by2.h
 *
 *  Created on: Oct 28, 2016
 *      Author: karibe
 */

#ifndef DECODER_1BY2_H_
#define DECODER_1BY2_H_
#include<systemc.h>

SC_MODULE(decoder){
//input and output ports
sc_in<bool> a;
sc_out<bool> b,c;
//constructor: where the processes are bound to simulation kernel
SC_CTOR(decoder){
	SC_METHOD(decode);
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
};




#endif /* DECODER_1BY2_H_ */
