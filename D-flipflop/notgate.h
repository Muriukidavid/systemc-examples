#include <systemc.h>

SC_MODULE(not_gate){
//input and output ports

sc_in<bool> x;
sc_out<bool> y;

  

void gate1(void);
~not_gate();


//constructor: where the processes are bound to simulation kernel
SC_CTOR(not_gate){
	SC_METHOD(gate1);
	sensitive << x ;
	//dont_initialize();
}
};










