#include "systemc.h" 

SC_MODULE(driver) {
	sc_out < sc_uint<4> > opA,opB;
	sc_out < sc_uint<3> > op;
	sc_in<bool> clk;

	void drive();

	SC_CTOR(driver)   {
		SC_THREAD(drive);
	} 
};
