/*
 * driver.h
 *
 *  Created on: Mar 4, 2016
 *      Author: karibe
 */

#ifndef DRIVE2_H_
#define DRIVE2_H_

#include<systemc>

SC_MODULE(driver){
sc_out<bool> d_m,d_n;

SC_CTOR(driver){
	SC_THREAD(drive);
	//dont_initialize();
}

void drive(void){
	while(1){
		d_m=0;
		d_n=0;
		wait(5,SC_NS);
		d_m=0;
		d_n=1;
		wait(5,SC_NS);
		d_m=1;
		d_n=0;
		wait(5,SC_NS);
		d_m=1;
		d_n=1;
		wait(5,SC_NS);
	}
}
};
#endif /* DRIVE2_H_ */
