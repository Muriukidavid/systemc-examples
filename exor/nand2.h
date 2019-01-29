#include "systemc.h"
SC_MODULE(nand2){
	sc_in<bool> A, B;       // input signal ports
	sc_out<bool> F;         // output signal ports

	void do_nand2(){
		F.write( !(A.read() && B.read()) );
	}
	SC_CTOR(nand2){
		SC_METHOD(do_nand2);  // register do_nand2 with kernel
		sensitive << A << B;  // sensitivity list
	}
};
