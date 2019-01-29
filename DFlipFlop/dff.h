#ifndef DFF_H_
#define DFF_H_
#include <systemc.h>
#include "../nand/nand.h"
#include "../not/notgate.h"

SC_MODULE (dff) {

	//ports
	sc_in <bool> clk{"Clock"}, clr{"Clear"}, din{"Input"}; //inputs
	sc_out <bool> dout{"Output"}; //data output port
	
	//nand gates
	nand_gate n1, n2, n3, n4;
	//not gate
	not_gate ng;
	//signals
  	sc_signal<bool>s_ng_n2, S1, S2, S3, S4;
  	
  	//functions
	void dff_process(void){
		if(clr){
			dout = 0;
		}else{
			dout = n3.out;
		}
	}
	~dff(){
	}
	
  	//constructor
	SC_CTOR(dff): n1("nand1"), n2("nand2"), n3("nand3"), n4("nand4"), ng("not"){
		//din
		n1.A(din);
		ng.in(din);
		//s_ng_n2
		ng.out(s_ng_n2);
		n2.A(s_ng_n2);
		//clk
		n1.B(clk);
		n2.B(clk);
		//S1
		n1.out(S1);
		n3.A(S1);
		//S3
		n2.out(S2);
		n4.B(S2);
		//S3
		n3.out(S3);
		n4.A(S3);
		//dout(S3);
		//S4
		n4.out(S4);
		n3.B(S4);
		
		//function for reading input
		 SC_METHOD (dff_process);
		sensitive<<clr<<clk.pos(); 
	}
};
#endif /* SHIFTREG_H_ */
