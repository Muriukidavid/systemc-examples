#ifndef DRIVER_H_
#define DRIVER_H_

#include <systemc.h>

SC_MODULE(driver) {     

	sc_out < sc_uint<4> > opcode,operand1,operand2;	// 4 bit width 
	sc_in <bool> clk;
	void drive (void);
	
	SC_CTOR(driver){     
		SC_THREAD(drive);
		sensitive << clk.pos();
	} 
};

#endif
