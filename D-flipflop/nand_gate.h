/*
 * nand_gate.h
 *
 *  Created on: Mar 4, 2016
 *      Author: kibet
 */

#ifndef NAND_GATE_H_
#define NAND_GATE_H_
#include<systemc.h>

SC_MODULE(nand_gate) {
//input and output ports
	sc_in<bool> a, b;
	sc_out<bool> c;


	~nand_gate();

	void gate(void);

//constructor: where the processes are bound to simulation kernel
	SC_CTOR(nand_gate) {
		SC_METHOD(gate);
		sensitive<<a<<b;
		//dont_initialize();
	}
};

#endif /* NAND_GATE_H_ */
