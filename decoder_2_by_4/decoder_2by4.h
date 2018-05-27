#ifndef DECODER_2BY4_H_
#define DECODER_2BY4_H_
#include<systemc.h>

SC_MODULE(decoder){

	//input and output ports
	sc_in<bool> A0,A1;
	sc_out<bool> D0,D1,D2,D3;
	
	//constructor: where the processes are bound to simulation kernel
	SC_CTOR(decoder){
		SC_METHOD(decode);
		sensitive<<A0;
		sensitive<<A1;
		//dont_initialize();
	}

	~decoder(){
	//delete stuff :P
	}

	void decode(void){
		D0 = (A0==0 && A1==0)?1:0;
		D1 = (A0==0 && A1==1)?1:0;
		D2 = (A0==1 && A1==0)?1:0;
		D3 = (A0==1 && A1==1)?1:0;
	}
	
};




#endif /* DECODER_2BY4_H_ */
