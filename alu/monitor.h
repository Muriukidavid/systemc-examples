#ifndef MONITOR_H_
#define MONITOR_H_

#include <systemc.h>
#include "iomanip"

using namespace std;

SC_MODULE(monitor) {     
	sc_in < sc_uint<4> > opcode,operand1,operand2, result;	// 4 bit width 
	sc_in <bool> zero, clk;
	
	void monita(void);

	SC_CTOR(monitor)   {     
		SC_THREAD(monita);
		sensitive << clk.pos() ;
	} 
};

#endif
