#include <systemc.h>
#include "nand_gate.h"
#include "../decoder1by2/not_gate.h"

SC_MODULE (dff) {
	sc_in <bool> clk;
	sc_in <bool> din;
	sc_out <bool> dout;

	sc_signal <bool> sig1, sig2, sig3, sig4, sig5;

	// Instances of nand gates
	nand_gate *nand_gate_1;
	nand_gate *nand_gate_2;
	nand_gate *nand_gate_3;
	nand_gate *nand_gate_4;

	//Instance of and gates
	not_gate *not_gate_1;


	void dff_method(void);

	~dff();

	SC_CTOR (dff) {
		SC_METHOD (dff_method);
			sensitive_pos << clk;

			nand_gate_1 = new nand_gate("nand_gate_1");
			nand_gate_2 = new nand_gate("nand_gate_2");
			nand_gate_3 = new nand_gate("nand_gate_3");
			nand_gate_4 = new nand_gate("nand_gate_4");

			not_gate_1 = new not_gate("not_gate_1");


			not_gate_1->a(din);
			not_gate_1->b(sig1);

			nand_gate_1->a(din);
			nand_gate_1->b(clk);
			nand_gate_1->c(sig2);

			nand_gate_2->a(clk);
			nand_gate_2->b(sig1);
			nand_gate_2->c(sig3);

			nand_gate_3->a(sig2);
			nand_gate_3->b(sig5);
			nand_gate_3->c(sig4);

			nand_gate_4->a(sig4);
			nand_gate_4->b(sig3);
			nand_gate_4->c(sig5);

	}

};
