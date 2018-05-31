/*
 * invertergate.h
 *
 *  Created on: may 23, 2018 
 *      Author: ruth ndunge
 */

#ifndef INVERTERGATE_H_
#define INVERTERGATE_H_
#include<systemc.h>

SC_MODULE(inverter_gate){
//input and output ports

sc_in<bool> x;
sc_out<bool> y,z;


//constructor: where the processes are bound to simulation kernel
SC_CTOR(inverter_gate){
	SC_METHOD(gate);
	sensitive << x;
	//dont_initialize();
}

~inverter_gate(){
//delete stuff :P
}

void gate(void){
	 y =! x;
     z = x;
     
}
};




#endif /* INVERTER_GATE_H_ */
