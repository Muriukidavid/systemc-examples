/*
 * and_gate.h
 *
 *  Created on: May 26, 2018
 *      Author: lundi
 */

#ifndef AND_GATE_H_
#define AND_GATE_H_
#include<systemc.h>

SC_MODULE(a_gate){
//input and output ports 
sc_in<bool>a,b;
sc_out<bool>c;
//constructor 
SC_CTOR(a_gate){
	SC_METHOD(getOutput);
	sensitive<<a<<b;
	//dont_initialize();
}

~a_gate(){
//delete from memory 
}
//method to get the output from 2 inputs
void getOutput(void){
	c=(a==1 && b==1)?1:0;
}
};


#endif /* AND_GATE_H */
