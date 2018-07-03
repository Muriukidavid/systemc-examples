#include <systemc.h>
#include "NOT.h"
#include "NAND.h"

SC_MODULE (dff) {
	sc_in <bool> clk;
	sc_in <bool> din;
	sc_signal <bool> sig1, sig2, sig3, sig4, sig5;
    sc_out <bool> dout;
    
    
    NANDGATE nand1;
    NANDGATE nand2;
    NANDGATE nand3;
    NANDGATE nand4;
	NOT notgt;
	
	void dff_method(void);
	~dff();
	SC_CTOR (dff): nand1("Instance1"),
		           nand2("Instance2"),
		           nand3("Instance3"),
		           nand4("Instance4"),
		           notgt("not gate instance")
                   
                   {

		notgt.not_a(din);
		notgt.not_b(sig1);

		nand1.a(din);
		nand1.b(clk);
		nand1.c(sig2);

		nand2.a(clk);
		nand2.b(sig1);
		nand2.c(sig3);

		nand3.a(sig2);
		nand3.b(sig5);
		nand3.c(sig4);

		nand4.a(sig4);
		nand4.b(sig3);
		nand4.c(sig5);


		SC_METHOD (dff_method);
			sensitive << clk.pos();
};

};
