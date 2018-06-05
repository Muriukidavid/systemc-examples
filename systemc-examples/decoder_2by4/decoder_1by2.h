/*
 * decoder_1by2.h
 *
 *  Created on: May 21, 2018
 *      Author: shaniz
 */
#ifndef DECODER_1BY2_H_
#define DECODER_1BY2_H_
#include<systemc.h>
#include"notgate.h"

SC_MODULE(decoder){

sc_in<bool> in;
sc_out<bool> out1,out2;

not_gate *ntgt1 ,*ntgt2;

//constructor: where the processes are bound to simulation kernel
SC_CTOR(decoder){
	
 	 ntgt1=new not_gate ("notgate_1");
	 ntgt2=new not_gate ("notgate_2");
}

~decoder(){
//delete stuff :P
	 delete ntgt1;
	 delete ntgt2;
}


};

#endif /* DECODER_2BY4_H_ */


