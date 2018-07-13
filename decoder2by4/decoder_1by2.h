/*
 * decoder_2by4.h
 *
 *  Created on: Mar 4, 2016
 *      Author: karibe
 */

#ifndef DECODER_1BY2_H_
#define DECODER_1BY2_H_
#include<systemc.h>
#include "notgate.h"

SC_MODULE(decoder){

	sc_in<bool> in;
	sc_out<bool> out1,out2;

	not_gate *ntgt1;

	//constructor: where the processes are bound to simulation kernel
	SC_CTOR(decoder){
		SC_METHOD(pass);
		sensitive<<in;
	 	 ntgt1=new not_gate ("notgate_1");
	 	 
	 	 ntgt1->in(in);
	 	 ntgt1->out(out1);
		 
	}
	
	void  pass(){
		out2 = in;
	}
	~decoder(){
	//delete stuff :P
		 delete ntgt1;
	}
};

#endif /* DECODER_2BY4_H_ */
