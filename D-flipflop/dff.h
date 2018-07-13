#ifndef DFF_H_
#define DFF_H_
#include <systemc.h>
#include "nand.h"
#include "notgate.h"

SC_MODULE (dff) {
	sc_in <bool> clk, clr, din;
	sc_out <bool> dout;
	
	nand2 *n1, *n2, *n3, *n4;
	
	not_gate *ng;

  	sc_signal<bool> sig, S1, S2, S3 , S4;
	SC_CTOR(dff)  {
		n1=new nand2("N1");
		n2=new nand2("N2");
		n3=new nand2("N3");
		n4=new nand2("N4");
		ng=new not_gate("NG");
			  
	   
		ng->in(sig);
		ng->out(S1);
		
		n1->A(sig);
		n1->B(clk);
		n1->F(S2);

		n2->A(S1);
		n2->B(clk);
		n2->F(S3);

		n3->A(S2);
		n3->B(S4);
		n3->F(dout);

		n4->A(dout);
		n4->B(S3);
		n4->F(S4);
		
		SC_METHOD (dff_method);
		sensitive << clk.pos();
	}

	void dff_method(void);
	~dff();

};
#endif /* SHIFTREG_H_ */