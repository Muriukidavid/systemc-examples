
#ifndef DRIVER_H_
#define DRIVER_H_

#include<systemc>

SC_MODULE(driver){
	sc_out<bool> d_A0;
	sc_out<bool> d_A1;

	SC_CTOR(driver){
		SC_THREAD(drive);
	}

	void drive(void){
		while(1){
			d_A0 = 0; d_A1 = 0;
			wait(5,SC_NS);
			d_A0 = 1; d_A1 = 0;
			wait(5,SC_NS);
			d_A0 = 0; d_A1 = 1;
			wait(5,SC_NS);
			d_A0 = 1; d_A1 = 1;
			wait(5,SC_NS);
		}
	}
};
#endif /* DRIVER_H_ */
