#include <systemc.h>
#include"../decoder1by2/inverter.h"
#include "nandgate.h"

SC_MODULE (dff) {
	sc_in <bool> clk;
	sc_in <bool> din;
	sc_out <bool> dout;
	sc_signal <bool> sig_in, sig_1, sig_2, sig_3, sig_4;

	nandgate nandgt1;
	nandgate nandgt2;
	nandgate nandgt3;
	nandgate nandgt4;
	notgate notgt;

	void dff_method(void);
	~dff();

	SC_CTOR (dff):nandgt1("nandgate_instance1"),nandgt2("nandgate_instance2"),nandgt3("nandgate_instance3"),nandgt4("nandgate_instance4"),notgt("notgate_instance"){

		nandgt1.in2(clk);
		nandgt2.in2(clk);

		nandgt1.out3(sig_2);
		nandgt3.in1(sig_2);

		nandgt2.out3(sig_3);
		nandgt4.in2(sig_3);

		nandgt3.in2(sig_4);
		nandgt4.out3(sig_4);

		nandgt3.out3(dout);
		nandgt4.in1(dout);

		nandgt1.in1(sig_in);
		notgt.d(sig_in);

		notgt.f(sig_1);
		nandgt2.in1(sig_1);

		SC_METHOD (dff_method);
			sensitive << clk.pos();
	}
};
