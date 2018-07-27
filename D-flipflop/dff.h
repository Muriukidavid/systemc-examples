#include <systemc.h>
#include "NandGate.h"

SC_MODULE (dff) {
	sc_in <bool> clk;
	sc_in <bool> in;
	sc_out <bool> Q,Q2;
	sc_in <bool> clk_A,clk_B,dinA,dinB,dinC,dinD,toggleC,toggleD;
	sc_out <bool> doutA,doutB,doutC,doutD;
	sc_signal<bool> s_din, s_dout, s_dff1, s_dff2, s2_dout;
	//sc_clock clock("clk",5,SC_NS,0.5);

/*
 *Create 4 instances of the nand gate
 *
 */
	Nand_Gate N1;
	Nand_Gate N2;
	Nand_Gate N3;
	Nand_Gate N4;


void dff_method (void);
	~dff();

	SC_CTOR (dff): N1,N2,N3,N4 {

		//First Nand gate inputs & output
			N1.Nand_in1(s_din);
			N1.Nand_in2(clock);
			N1.Nand_out(s_dff1);

		//	second Nand gate inputs & output
			N2.Nand_in1(s_din);
			N2.Nand_in2(clock);
			N2.Nand_out(s_dff2);

		//	Third Nand gate inputs & output
			N3.Nand_in1(s_dff1);
			N3.Nand_in2(s2_dout);
			N3.Nand_out(s_dout);

		//	Fouth Nand gate inputs & output
			N4.Nand_in1(s_dout);
			N4.Nand_in2(s_dff2);
			N4.Nand_out(s2_dout);

		SC_METHOD (dff_method);
		sensitive_pos << clk_A;
	}
};
