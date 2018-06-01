/*
 * and_gate.h
 *
 *  Created on: May 26, 2018
 *      Author: lundi
 */

#ifndef INVERTER_H_
#define INVERTER_H_
#include<systemc.h>

SC_MODULE(inverter){
	//input and output ports 
	sc_in<bool>x;
	sc_out<bool>y;
	//constructor 
	SC_CTOR(inverter){
		SC_METHOD(invat);
		sensitive<<x;
		//dont_initialize();
	}

	~inverter(){
	//delete from memory 
	}
	//method to invert the given output
	void invat(void){
		y=(x==0)?1:0;
	}
};


#endif /* INVERTER_H_ */
