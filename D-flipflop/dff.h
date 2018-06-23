#include <systemc.h>

SC_MODULE (dff) {
	sc_in <bool> clk;
	sc_in <bool> din;
	sc_out <bool> dout;

	void dff_method(void);
	~dff();

	SC_CTOR (dff) {
		SC_METHOD (dff_method);
			sensitive << clk.pos();
	}
};
