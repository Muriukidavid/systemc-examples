/*
 * driver.h
 *
 *  Created on: May 21, 2018
 *      Author: shaniz
 */

#ifndef DRIVE2_H_
#define DRIVE2_H_

#include<systemc.h>
//declaration of driver
SC_MODULE(driver){
//input
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


