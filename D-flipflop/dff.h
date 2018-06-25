#include <systemc.h>
#include "nandgate.h"
#include "../decoder1by2/notGate.h"

SC_MODULE (dff) {
	sc_in <bool> clk;
	sc_in <bool> din;
	sc_out <bool> dout;
	sc_signal <bool> in, sig1, sig2, sig3, sig4;

	nandgate nand1;
    nandgate nand2;
    nandgate nand3;
    nandgate nand4;
	notgate notgt;
    

	void dff_method(void);
	~dff();

	SC_CTOR (dff)   :nand1("nand_instance_1")
					,nand2("nand_instance_2")
					,nand3("nand_instance_3")
					,nand4("nand_instance_4")
					,notgt("not_instance") {
		
		nand1.x(in);
		notgt.o(in);

		nand1.y(clk);
		nand2.y(clk);

		notgt.p(sig1);
		nand2.x(sig1);

		nand1.z(sig2);
		nand3.x(sig2);

		nand2.z(sig3);
		nand4.y(sig3);

		nand3.y(sig4);
		nand4.z(sig4);

		nand3.z(dout);
		nand4.x(dout);


		SC_METHOD (dff_method);
			sensitive << clk.pos();
	}
};
