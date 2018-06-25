/*
 * decoder_2by4.h
 *
 *  Created on: Mar 4, 2016
 *      Author: karibe
 */

#ifndef DECODER_1BY2_H_
#define DECODER_1BY2_H_
#include<systemc.h>

SC_MODULE(decoder){
//input and output ports
sc_in<bool> m, n;
sc_out<bool> o, p, r, s;
//constructor: where the processes are bound to simulation kernel
SC_CTOR(decoder){
	SC_METHOD(decode);
	sensitive<<m<<n;
	//dont_initialize();
}

~decoder(){
//delete stuff :P
}

void decode(void){
	o = ( n==0 && m==0 )?1:0;
	p = ( n==0 && m==1 )?1:0;
	r = ( n==1 && m==0 )?1:0;
	s = ( n==1 && m==1 )?1:0;

}
};




#endif /* DECODER_2BY4_H_ */
