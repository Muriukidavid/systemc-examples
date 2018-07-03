#include <systemc.h>
#include "nandgate.h"
#include "inverter.h"

SC_MODULE (dff) {
	sc_in <bool> clk;
	sc_in <bool> din;
	sc_out <bool> dout;
	sc_signal <bool> s_in,s_nand1nand3, s_nand2inv, s_nand2nand4, s_dout_prime;
	nandgate *nand1, *nand2, *nand3, *nand4;
	inverter *notgate;
	void dff_method(void);
	~dff();

	SC_CTOR (dff){
		nand1 = new nandgate("nandgate_instance_1");
		nand2 = new nandgate("nandgate_instance_2");
		nand3 = new nandgate("nandgate_instance_3");
		nand4 = new nandgate("nandgate_instance_4");
		notgate = new inverter("invertergate_instance_1");
		
		nand1->x_nand(din);
		notgate->inv_x(din);

		nand1->y_nand(clk);
		nand2->y_nand(clk);

		notgate->inv_y(s_nand2inv);
		nand2->x_nand(s_nand2inv);

		nand1->z_nand(s_nand1nand3);
		nand3->x_nand(s_nand1nand3);

		nand2->z_nand(s_nand2nand4);
		nand4->y_nand(s_nand2nand4);

		nand3->y_nand(s_dout_prime);
		nand4->z_nand(s_dout_prime);

		nand3->z_nand(dout);
		nand4->x_nand(dout);


		SC_METHOD (dff_method);
			//sensitive << clk.pos();
	}
};
