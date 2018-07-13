#include <systemc.h>
#include "nand.h"
#include "notgate.h"

SC_MODULE (dff) {
	sc_in <bool> clk;
	sc_in <bool> din;
	sc_out <bool> dout;
	
	nand *n1, *n2, *n3, *n4;
	
	not_gate *ng;

  sc_signal<bool> sig, S1, S2, S3 , S4;
		SC_CTOR(dff)  {
		n1=new nand("nand1");
		n2=new nand("nand2");
		n3=new nand("nand3");
		n4=new nand("nand4");
		ng=new not_gate("notgate");
		  
   
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
	sensitive_pos<< clk;
  }

	void dff_method(void);
	~dff();

};
