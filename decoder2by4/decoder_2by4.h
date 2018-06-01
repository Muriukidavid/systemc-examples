/*
 * decoder_2by4.h
 *
 *  Created on: Mar 4, 2016
 *      Author: Kibet
 */

#ifndef DECODER_2BY4_H_
#define DECODER_2BY4_H_
#include<systemc.h>

#include "../decoder1by2/decoder_1by2.h"

SC_MODULE(decoder2by4) {
//input and output ports
	sc_in<bool> a, b;
	sc_out<bool> c, d, e, f;

	// Instances of decoder 1by2
	decoder *dec_1;
	decoder *dec_2;

//constructor: where the processes are bound to simulation kernel
	SC_CTOR(decoder2by4) {
		SC_METHOD(decode);
		sensitive<<a<<b;

		dec_1 = new decoder("dec_1by2_1");
		dec_2 = new decoder("dec_1by2_2");

		dec_1->a(a);
		dec_2->a(b);

		dec_1->b(c);
		dec_1->c(d);

		dec_2->b(e);
		dec_2->c(f);
	}

	~decoder2by4() {
	}

	void decode(void) {

	}
};

#endif /* DECODER_2BY4_H_ */
