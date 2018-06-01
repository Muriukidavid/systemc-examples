
#ifndef DECODER_2BY4_H_
#define DECODER_2BY4_H_
#include<systemc.h>

SC_MODULE(decoder){
	//input and output ports
	sc_in<bool> b;
	sc_out<bool> c,d;
	//constructor: where the processes are bound to simulation kernel
	SC_CTOR(decoder){
		SC_METHOD(decode);
		sensitive<<b;
		//dont_initialize();
	}

	~decoder(){
	//delete stuff :P
	}

	void decode(void){
		c=(b==0)?1:0;
		d=(b==1)?1:0;
	}
};




#endif /* DECODER_2BY4_H_ */
