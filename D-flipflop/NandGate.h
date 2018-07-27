/*
 * NandGate.h
 *
 *  Created on: Jun 26, 2018
 *      Author: njoro
 */

#include<systemc>

SC_MODULE(Nand_Gate){
	// input and output ports
	sc_in<bool> Nand_in1,Nand_in2;
	sc_out<bool> Nand_out;

	void add_invert(void);
	~Nand_Gate();

	SC_CTOR(Nand_Gate){
		SC_METHOD(add_invert);
		sensitive<<Nand_in1, Nand_in2;
		dont_initialize();
	}

};



