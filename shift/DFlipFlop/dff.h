#ifndef DFF_H_
#define DFF_H_
#include <systemc.h>
#include "../nand/nand.h"
#include "../not/notgate.h"

SC_MODULE (dff) {
	sc_in <bool> clk, clr, din;
	sc_inout <bool> dout;
	
	nand n1, n2, n3, n4;
	
	not_gate ng;

  	sc_signal<bool>  S1, S2, S3 , S4;
	SC_CTOR(dff) :	n1("N1"),n2("N2"),n3("N3"),n4("N4"),ng("NG") {
		//port 
	    ng.in(din);
	    n1.A(din);
	    //S1
		ng.out(S1);
		n2.A(S1);
		//CLK
		n1.B(clk);
		n2.B(clk);
		//S2
		n1.F(S2);
		n4.A(S2);
		//S3
		n2.F(S3);
		n3.B(S3);
		//S4
		n4.B(S4);
		n3.F(S4);
		//port
		n4.F(dout);
		
		
		
		
		SC_METHOD (dff_method);
		sensitive <<clr << clk.pos();
	}

	void dff_method(void);
	//~dff();

};
#endif /* SHIFTREG_H_ */
