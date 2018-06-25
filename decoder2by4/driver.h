/*
 * driver.h
 *
 *  Created on: Mar 4, 2016
 *      Author: karibe
 */

#ifndef DRIVER_H_
#define DRIVER_H_

#include<systemc>

SC_MODULE(driver){
sc_out<bool> d_m, d_n;

SC_CTOR(driver){
	SC_THREAD(drive);
}

void drive(void){
	while(1){
		d_n=0;
		d_m=0;
		wait(5,SC_NS);

		d_n=0;
		d_m=1;
		wait(5,SC_NS);

		d_n=1;
		d_m=0;
		wait(5,SC_NS);

		d_n=1;
		d_m=1;
		wait(5,SC_NS);
	}
}
};
#endif /* DRIVER_H_ */
