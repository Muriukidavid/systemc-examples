/*
 * andgate.h
 *
 *  Created on: Mar 4, 2016
 *      Author: karibe
 */

#ifndef ANDGATE_H_
#define ANDGATE_H_
#include<systemc.h>

SC_MODULE(andgate){
//input and output ports

sc_in<bool> x, y;
sc_out<bool> z;


//constructor: where the processes are bound to simulation kernel
SC_CTOR(andgate){
	SC_METHOD(gate);
	sensitive << x << y;
	//dont_initialize();
}

~andgate(){
//delete stuff :P
}

void gate(void){
	z = x && y;
}
};




#endif /* AND_GATE_H_ */
