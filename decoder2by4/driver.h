
#ifndef DRIVER_H_
#define DRIVER_H_

#include<systemc.h>

SC_MODULE(driver){
	sc_out<bool> d_x2;
	sc_out<bool> d_a0;
	sc_out<bool> d_a1;


	SC_CTOR(driver){
		SC_THREAD(drive);
	}

	void drive(void){
		while(1){
			d_x2 = 1; d_a0 = 0; d_a1 = 0; 
			wait(5,SC_NS);
			d_x2 = 1; d_a0 = 1; d_a1 = 0; 
			wait(5,SC_NS);
			d_x2 = 1; d_a0 = 0; d_a1 = 1; 
			wait(5,SC_NS);
			d_x2 = 1; d_a0 = 1; d_a1 = 1; 
			wait(5,SC_NS);
		}
	}
};
#endif /* DRIVER_H_ */
