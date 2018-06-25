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
sc_out<bool> d_a1,d_a2;

SC_CTOR(driver){
	SC_THREAD(drive);
}

void drive(void){
	while(1){
		d_a1=0; d_a2=0;
		wait(5,SC_NS);
		d_a2=1;
		wait(5,SC_NS);

                d_a1=1; d_a2=0;
		wait(5,SC_NS);
		d_a2=1;
		wait(5,SC_NS);
	}
}
};
#endif /* DRIVER_H_ */
