	
#ifndef INVERTER_OPERATION_H_
#define INVERTER_OPERATION_H_
#include<systemc.h>

SC_MODULE(inverter){
	//input and output ports
	sc_in<bool> x1, k, m;
	sc_out<bool> c, d;
	//constructor: where the processes are bound to simulation kernel
	SC_CTOR(inverter){
		SC_METHOD(invert);
		sensitive << x1 << k << m;
		//dont_initialize();
	}

	~inverter(){
	//delete stuff :P
	}

	void invert(void){				
		c=(x1==1 && k==1)?1:0;
		d=(x1==0 && m==1)?1:0;
	}
};

#endif 
