#include <systemc.h>

SC_MODULE(driver){
	sc_out<bool> d_in;
	
	void drive(void);
	
	SC_CTOR(driver){
		SC_THREAD(drive);
	}
};
