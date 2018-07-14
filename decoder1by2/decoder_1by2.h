/*
 * decoder_2by4.h
 *
 *  Created on: Mar 4, 2016
 *      Author: karibe
 */

#ifndef DECODER_1BY2_H_
#define DECODER_1BY2_H_
#include<systemc.h>

#include "not_gate.h"

SC_MODULE(decoder) {
//input and output ports
	sc_in<bool> a;
	sc_out<bool> b, c;

	not_gate *not_gate_1;

//constructor: where the processes are bound to simulation kernel
	SC_CTOR(decoder) {
		not_gate_1 = new not_gate("not_gate_1");

		not_gate_1->a(a);
		not_gate_1->b(b);

		SC_METHOD (decode);
		sensitive<<a;
		//dont_initialize();
	}

	~decoder() {
//delete stuff :P
	}

	void decode(void) {
		c = a;
	}
};

#endif /* DECODER_2BY4_H_ */
