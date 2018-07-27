#ifndef AND_Gate_H_
#define AND_Gate_H_
#include<iostream>
#include<systemc>

SC_MODULE(anding_gate){
	// input and output ports
	sc_in<bool> g1_a, g1_b, g2_a, g2_b, g3_a, g3_b, g4_a, g4_b;
	sc_out<bool> g1_result, g2_result, g3_result, g4_result;

	SC_CTOR(anding_gate){
		SC_METHOD(anding);
		sensitive<<g1_a<<g1_b<<g2_a<<g2_b<<g3_a<<g3_b<<g4_a<<g4_b;	
	}

	~anding_gate(){}

	void anding(void){
			g1_result=(g1_a==1 && g1_b==1)?1:0;
			g2_result=(g2_a==1 && g2_b==1)?1:0;
			g3_result=(g3_a==1 && g3_b==1)?1:0;
			g4_result=(g4_a==1 && g4_b==1)?1:0;
	}
};

#endif



