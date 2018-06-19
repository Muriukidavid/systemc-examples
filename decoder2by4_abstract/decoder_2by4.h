/*
 * decoder_2by4.h
 *
 *  Created on: Mar 4, 2016
 *      Author: karibe
 */

#ifndef DECODER_2BY4_H_
#define DECODER_2BY4_H_
#include<systemc.h>

SC_MODULE(decoder){
//input and output ports
sc_in<bool> a,d;
sc_out<bool> b,c,e,f;
//constructor: where the processes are bound to simulation kernel
SC_CTOR(decoder){
	SC_METHOD(decode);
	sensitive<<a;
	sensitive<<d;
	//dont_initialize();
}

~decoder(){
//delete stuff :P
}

void decode(void){
	b=(a==0&&d==0)?1:0;
	c=(a==0&&d==1)?1:0;
	e=(a==1&&d==0)?1:0;
	f=(a==1&&d==1)?1:0;
}
};




#endif /* DECODER_2BY4_H_ */
