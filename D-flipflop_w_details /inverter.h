#include <systemc.h>

SC_MODULE(inverter){
	//input and output ports
	sc_in<bool> inv_x;
	sc_out<bool> inv_y;

	void inv_gate(void);
	~inverter();

	//constructor: where the processes are bound to simulation kernel
	SC_CTOR(inverter){
		//dont_initialize();
		SC_METHOD(inv_gate);
		sensitive <<inv_x;
	}
};

