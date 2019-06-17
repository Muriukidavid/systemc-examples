#ifndef NOTGATE_H_
#define NOTGATE_H_
#include<systemc.h>

SC_MODULE(not_gate){
	//input and output ports
	sc_in<bool> in;
	sc_out<bool> out;


	//constructor: where the processes are bound to simulation kernel
	SC_CTOR(not_gate){
		SC_METHOD(gate);
		sensitive << in;
		//dont_initialize();
	}

	~not_gate(){
	//delete stuff :P
	}

	void gate(void){
		out = !in;
	}
};

#endif /* NOTGATE_H_ */


