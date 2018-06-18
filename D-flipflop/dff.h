#include <systemc.h>

SC_MODULE (dff) {
	sc_in<bool> clk;
	sc_in<bool> din1;
	sc_in<bool> din2;
	sc_in<bool> din3;
	sc_in<bool> din4;
	sc_in<bool> din5;
	sc_in<bool> din6;
	sc_in<bool> din7;

	sc_out<bool> dout1;
	sc_out<bool> dout2;
	sc_out<bool> dout3;
	sc_out<bool> dout4;
	sc_out<bool> dout5;

	void dff_method(void);
	~dff();

	SC_CTOR (dff) {
		SC_METHOD (dff_method);
			sensitive_pos << clk;
	}
};
