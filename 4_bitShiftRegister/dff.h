#include <systemc.h>
#include "nandgate.h"
#include "inverter.h"

SC_MODULE (dff) {
	sc_in <bool> clk;
	sc_in <bool> din;
	sc_out <bool> dout;
	sc_signal <bool> s_in,s_nand1nand3, s_nand2inv, s_nand2nand4, s_dout_prime;
	nandgate nand1;
	nandgate nand2;
	nandgate nand3;
	nandgate nand4;
	inverter notgate;

	void dff_method(void);
	~dff();

	SC_CTOR (dff)   :nand1("nandgate_instance_1")
			,nand2("nandgate_instance_2")
			,nand3("nandgate_instance_3")
			,nand4("nandgate_instance_4")
			,notgate("invertergate_instance_1") {
		notgate.inv_y(s_nand2inv);
		notgate.inv_x(s_in);

		nand1.x_nand(s_in);
		nand1.y_nand(clk);
		nand1.z_nand(s_nand1nand3);

		nand2.x_nand(s_nand2inv);
		nand2.y_nand(clk);
		nand2.z_nand(s_nand2nand4);

		nand3.x_nand(s_nand1nand3);
		nand3.y_nand(s_dout_prime);
		nand3.z_nand(dout);

		nand4.x_nand(dout);
		nand4.y_nand(s_nand2nand4);
		nand4.z_nand(s_dout_prime);


		SC_METHOD (dff_method);
			sensitive << clk.pos();
	}
};
