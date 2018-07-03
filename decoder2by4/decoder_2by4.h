/*
 * decoder_2by4.h
 *
 *  Created on: Mar 4, 2016
 *      Author: Elkana
 */

#ifndef DECODER_2BY4_H_
#define DECODER_2BY4_H_
#include<systemc.h>

#include "../decoder1by2/decoder_1by2.h"
#include "and_gate.h"

SC_MODULE(decoder2by4) {
//input and output ports
	sc_in<bool> a, b;
	sc_signal<bool> c, d, e, f;

	sc_out<bool> out_1, out_2, out_3, out_4;

	// Instances of decoder 1by2
	decoder *dec_1;
	decoder *dec_2;

	// Instances of and gates
	and_gate *gate_1;
	and_gate *gate_2;
	and_gate *gate_3;
	and_gate *gate_4;

//constructor: where the processes are bound to simulation kernel
	SC_CTOR(decoder2by4) {
		SC_METHOD(decode);
		sensitive<<a<<b;

		dec_1 = new decoder("dec_1by2_1");
		dec_2 = new decoder("dec_1by2_2");

		gate_1 = new and_gate("gate_1");
		gate_2 = new and_gate("gate_2");
		gate_3 = new and_gate("gate_3");
		gate_4 = new and_gate("gate_4");

		dec_1->a(a);
		dec_2->a(b);

		dec_1->b(c);
		dec_1->c(d);

		dec_2->b(e);
		dec_2->c(f);

		gate_1->a(c);
		gate_1->b(e);
		gate_1->c(out_1);

		gate_2->a(c);
		gate_2->b(f);
		gate_2->c(out_2);

		gate_3->a(d);
		gate_3->b(e);
		gate_3->c(out_3);

		gate_4->a(f);
		gate_4->b(d);
		gate_4->c(out_4);

	}

	~decoder2by4() {
	}

	void decode(void) {

	}
};

#endif /* DECODER_2BY4_H_ */
