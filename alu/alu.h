#include "systemc.h"

SC_MODULE(alu)
{
	sc_in < sc_uint<3> > op;
	sc_in < sc_uint<4> > opA, opB;
	sc_out < bool > carry, zero;
	sc_out < sc_uint<4> > result;

	sc_uint<5> temp_result;

    void calculate(void);

	SC_CTOR(alu){
		SC_METHOD(calculate);
			sensitive << opA  << opB << op;
	}

};
