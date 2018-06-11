

#ifndef ANDGATE_H_
#define ANDGATE_H_
#include<systemc.h>

SC_MODULE(andgate){
//inputs and output 

sc_in<bool> a, b;
sc_out<bool> c;


//constructor: where the processes are bound to simulation kernel
SC_CTOR(andgate){
	SC_METHOD(gate);
	sensitive << a << b;
	//dont_initialize();
}

~andgate(){
//delete stuff :P
}

void gate(void){
	c = a && b;
}
};




#endif /* AND_GATE_H_ */
