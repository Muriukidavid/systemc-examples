#include <systemc.h>
#include"inverter.h"
#include "nandgate.h"

SC_MODULE (dff) {
	sc_in <bool> clk;
	sc_in <bool> din;
	sc_out <bool> dout;
	sc_signal <bool> sig_in, sig_1, sig_2, sig_3, sig_4;

	nandgate gate1;
	nandgate gate2;
	nandgate gate3;
	nandgate gate4;
	notgate notgate1;

	void dff_method(void);
	~dff();

	SC_CTOR (dff):gate1("nandgate_instance1"),
				gate2("nandgate_instance2"),
				gate3("nandgate_instance3"),
				gate4("nandgate_instance4"),
				notgate1("notgate_instance"){

		gate1.in2(clk);
		gate2.in2(clk);

		gate1.out3(sig_2);
		gate3.in1(sig_2);

		gate2.out3(sig_3);
		gate4.in2(sig_3);

		gate3.in2(sig_4);
		gate4.out3(sig_4);

		gate3.out3(dout);
		gate4.in1(dout);

		gate1.in1(sig_in);
		notgate1.d(sig_in);

		notgate1.f(sig_1);
		gate2.in1(sig_1);

		SC_METHOD (dff_method);
			sensitive << clk.pos();
	}
};
