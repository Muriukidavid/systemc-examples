/*
 * decoder_2by4.h
 *
 *  Created on: May 24, 2018
 *      Author: Evans
 */
#ifndef ANDGATE_H_
#define ANDGATE_H_
#include<systemc.h>

SC_MODULE(gate){
//input and output ports
sc_in<bool> x, y;
sc_out<bool> z;
//constructor: where the processes are bound to simulation kernel
SC_CTOR(andgate){
	SC_METHOD(and_gate);
	sensitive<<x<<y;
	//dont_initialize();
}
~andgate(){
//delete stuff :P
}
void and_gate(void){
	z = (x==1 && y==1)?1:0;
}
};
#endif /* ANDGATE_H_ */
