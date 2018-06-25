#include <systemc.h>

SC_MODULE(nand_gate){
//input and output ports

sc_in<bool> a, b;
sc_out<bool> c;



void gate(void);
	~nand_gate();



//constructor: where the processes are bound to simulation kernel
SC_CTOR(nand_gate){
	SC_METHOD(gate);
	sensitive << a << b;
	//dont_initialize();
    

}

};

