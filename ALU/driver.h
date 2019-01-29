#include <systemc.h>

SC_MODULE(driver){
	sc_out < sc_uint<3> > d_OPCODE;
	sc_out < sc_uint<4> > d_OP1, d_OP2;
	
	//some local variables to operate on
	sc_uint<3> z;
	sc_uint<4> x, y;
	
	void drive(void);
	
	SC_CTOR(driver){
		SC_THREAD(drive);
	}
};
