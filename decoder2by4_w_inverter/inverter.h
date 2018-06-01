/*
 * andgate.h
 *
 *  Created on: Mar 4, 2016
 *      Author: karibe
 */

#ifndef INVERTER_H_
#define INVERTER_H_
#include<systemc.h>

SC_MODULE(inverter){
//input and output ports

sc_in<bool> inv_x;
sc_out<bool> inv_y,inv_z;


//constructor: where the processes are bound to simulation kernel
SC_CTOR(inverter){
	SC_METHOD(inv_gate);
	sensitive <<inv_x;
	//dont_initialize();
}

~inverter(){
//delete stuff :P
}

void inv_gate(void){
	inv_y = !inv_x;
	inv_z = inv_x;
}
};




#endif /* AND_GATE_H_ */
