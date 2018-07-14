#include <systemc.h>

SC_MODULE(monitor) {
	sc_in < sc_uint<4> > opA, opB,result;
	sc_in < sc_uint<3> > op;
	sc_in <bool> clk, zero, carry;

	void mon(void);

	SC_CTOR(monitor)   {
		SC_THREAD(mon);
			sensitive << clk.pos() ;
	}
};
