#include "systemc.h"

SC_MODULE(ALU)
{
	sc_in < sc_uint<3> > OPCODE;
	sc_in < sc_uint<4> > OP1,OP2;
	sc_out < bool > CARRY, ZERO;
	sc_out < sc_uint<4> > RESULT;

    sc_uint<4> data1, data2;
    sc_uint<5> result;

    void operate();
    
	SC_CTOR(ALU){
		SC_METHOD(operate);
			sensitive << OP1 << OP2 << OPCODE;
	}
};
