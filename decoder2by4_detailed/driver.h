/*
 * driver.h
 *
 *  Created on: May 22, 2018
 *      Author: ruthie
 */
#ifndef DRIVER_H_
#define DRIVER_H_

#include<systemc>

SC_MODULE(driver){
sc_out<bool> d_a,d_b;

SC_CTOR(driver){
	SC_THREAD(drive);
}

void drive(void){
	while(1){
		d_a=0;
		d_b=0;
		wait(5,SC_NS);
		d_a=0;
		d_b=1;
		wait(5,SC_NS);
		d_a=1;
		d_b=0;
		wait(5,SC_NS);
		d_a=1;
		d_b=1;
		wait(5,SC_NS);
	}
}
};
#endif /* DRIVE2_H_ */






