/*
 * inverter.h
 *
 *  Created on: Mar 4, 2016
 *      Author: Elkana
 */

#ifndef NOT_GATE_H_
#define NOT_GATE_H_
#include<systemc.h>

SC_MODULE(not_gate) {
//input and output ports
	sc_in<bool> a;
	sc_out<bool> b;
//constructor: where the processes are bound to simulation kernel
	SC_CTOR(not_gate) {
		SC_METHOD(gate);
		sensitive<<a;
		//dont_initialize();
	}

	~not_gate() {
//delete stuff :P
	}

	void gate(void) {
		b = !a;
	}
};

#endif /* NOT_GATE_H_ */
