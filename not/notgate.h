#ifndef NOTGATE_H_
#define NOTGATE_H_
#include<systemc.h>

SC_MODULE(not_gate){
	//input and output ports
	sc_in<bool> in;
	sc_out<bool> out;

	void n_gate(void);

	//constructor: where the processes are bound to simulation kernel
	SC_CTOR(not_gate){
		SC_METHOD(n_gate);
		sensitive << in;
	}	
};

#endif /* NOTGATE_H_ */


