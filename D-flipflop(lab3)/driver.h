#include <systemc.h>

SC_MODULE(driver){
	sc_out<bool> d_din;
	sc_out<bool> d_din1;
	sc_out<bool> d_din2;
	
	void drive(void);
	
	SC_CTOR(driver){
		SC_THREAD(drive);
	}
};
