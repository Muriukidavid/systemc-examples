#include "systemc.h"
#include "nand2.h"
SC_MODULE(exor2){
	//ports
	sc_in<bool> A, B;
	sc_out<bool> F;
	//module instances
	nand2 n1, n2, n3, n4;
	//signals
	sc_signal<bool> S1, S2, S3;

	SC_CTOR(exor2) : n1("N1"), n2("N2"), n3("N3"), n4("N4"){
		//Port A
		n1.A(A);
		n2.A(A);
		//Port B
		n1.B(B);
		n3.B(B);
		//Signal S1
		n1.F(S1);
		n2.B(S1);
		n3.A(S1);
		//Signal S2
		n2.F(S2);
		n4.A(S2);
		//Signal S3
		n3.F(S3);
		n4.B(S3);
		//Port F
		n4.F(F);
	}
};
