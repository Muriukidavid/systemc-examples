#ifndef DECODER_2BY4_H_
#define DECODER_2BY4_H_
#include<systemc.h>

SC_MODULE(decoder){
	//input and output ports
	sc_in<bool> in;
	sc_out<bool> out1,out2;
	//constructor: where the processes are bound to simulation kernel
	SC_CTOR(decoder){
		SC_METHOD(decode);
		sensitive<<in;
		//dont_initialize();
	}

	~decoder(){
	//delete stuff :P
	}

	void decode(void){
		out1=(in==0)?1:0;
		out2=(in==1)?1:0;
	}
};


#endif /* DECODER_2BY4_H_ */

