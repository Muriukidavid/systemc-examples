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
sc_in<bool> a1,a2;
sc_out<bool> b1,b2,b3,b4;
//constructor: where the processes are bound to simulation kernel
SC_CTOR(decoder){
	SC_METHOD(decode);
	sensitive<<a1;
	sensitive<<a2;
	//dont_initialize();
}

~decoder(){
//delete stuff :P
}

void decode(void){
	
    b1=(a1==0&&a2==0)?1:0;
    b2=(a1==0&&a2==1)?1:0;
    b3=(a1==1&&a2==0)?1:0;
    b4=(a1==1&&a2==1)?1:0;
}
};




#endif /* DECODER_2BY4_H_ */
