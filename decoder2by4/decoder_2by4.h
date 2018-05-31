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
sc_in<bool> a, b;
sc_out<bool> m, n, o, p;
//constructor: where the processes are bound to simulation kernel
SC_CTOR(decoder){
	SC_METHOD(decode);
	sensitive<<a<<b;
	//dont_initialize();
}

~decoder(){
//delete stuff :P
}

void decode(void){
	m = ( b==0 && a==0 )?1:0;
	n = ( b==0 && a==1 )?1:0;
	o = ( b==1 && a==0 )?1:0;
	p = ( b==1 && a==1 )?1:0;

}
};




#endif /* DECODER_2BY4_H_ */
