#ifndef OPERATIONS_H_
#define OPERATIONS_H_

#include <systemc.h>

SC_MODULE(operation){

	sc_in < sc_uint<4> > opcode,operand1,operand2;	// 4 bit width 
	sc_out < sc_uint<4> > result;
	sc_out <bool> zero;
	sc_uint	<4> op, op1, op2, res;

	void operate(void);

	SC_CTOR(operation){
		SC_THREAD(operate);	
		sensitive << opcode << operand1 << operand2;
	} 
};

#endif
