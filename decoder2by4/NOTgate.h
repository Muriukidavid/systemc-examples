	
#ifndef INVERTER_OPERATION_H_
#define INVERTER_OPERATION_H_
#include<systemc.h>

SC_MODULE(inverter){
	//input and output ports
	sc_in<bool> a, b, c;
	sc_out<bool> out1, out2;
	//constructor: where the processes are bound to simulation kernel
	SC_CTOR(inverter){
		SC_METHOD(invert);
		sensitive << a << b << c;
		//dont_initialize();
	}

	~inverter(){
	//delete stuff :P
	}

	void invert(void){				
		out1=(a==1 &&b ==1)?1:0;
		out2=(a==0 && c==1)?1:0;
	}
};

#endif 
