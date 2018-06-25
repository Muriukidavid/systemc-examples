<<<<<<< HEAD
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
||||||| merged common ancestors
=======
#include <systemc.h>

SC_MODULE (dff) {
	sc_in <bool> clk;
	sc_in <bool> din;
	sc_out <bool> dout;

	void dff_method(void);
	~dff();

	SC_CTOR (dff) {
		SC_METHOD (dff_method);
			sensitive_pos << clk;
	}
};
>>>>>>> bf9f72666fbec1eeb586f1f72fdaff7fdf95539f
