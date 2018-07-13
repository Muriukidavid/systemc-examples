#ifndef ANDGATE_H_
#define ANDGATE_H_
#include<systemc.h>

SC_MODULE(and_gate){
//input and output ports

sc_in<bool> A, B;
sc_out<bool> F;


//constructor: where the processes are bound to simulation kernel
SC_CTOR(and_gate){
	SC_METHOD(gate);
	sensitive << A << B;
	//dont_initialize();
}

~and_gate(){
//delete stuff :P
}

void gate(void){
	F = A&B;

}
};

#endif /* AND_GATE_H_ */