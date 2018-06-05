#ifndef ANDGATE_H_
#define ANDGATE_H_
#include<systemc.h>

SC_MODULE(not_gate){
//input and output ports

sc_in<bool> in;
sc_out<bool> out1,out2;


//constructor: where the processes are bound to simulation kernel
SC_CTOR(not_gate){
	SC_METHOD(gate);
	sensitive << in;
	//dont_initialize();
}

~not_gate(){
//delete stuff :P
}

void gate(void){
	out1 = !in;
	out1 = in;

}
};

#endif /* AND_GATE_H_ */


