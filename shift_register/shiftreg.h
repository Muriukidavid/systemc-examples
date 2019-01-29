#ifndef SHIFTREG_H_
#define SHIFTREG_H_
#include <systemc.h>
#include "../DFlipFlop/dff.h"

SC_MODULE (shiftreg) {

	sc_in <bool> clk{"clk_input"}, clr{"clr"}, din{"data_input"};
	sc_out <bool> QA, QB, QC, QD;
	
	dff DFFA, DFFB, DFFC, DFFD;
   	sc_signal<bool> s_QA, s_QB, s_QC, s_QD;
   	
   	void shift(void){
   		QA = s_QA;
   		QB = s_QB;
   		QC = s_QC;
   		QD = s_QD;
   	}
   	
   	~shiftreg(){
   		delete DFFA;
   		delete DFFB;
   		delete DFFC;
   		delete DFFD;
   	}
   	
	SC_CTOR(shiftreg): DFFA("dffa"), DFFB("dffb"), DFFC("dffc"), DFFD("dffd"){
		//input
		//din(sDin);
		DFFA.din(din);
		//s_QA
		DFFA.dout(s_QA);
		DFFB.din(s_QA);
		//s_QB
		DFFB.dout(s_QB);
		DFFC.din(s_QB);
		//s_QC
		DFFC.dout(s_QC);
		DFFD.din(s_QC);
		//s_QD
		DFFD.dout(s_QD);
		
		//clk connections
		DFFA.clk(clk);
		DFFB.clk(clk);
		DFFC.clk(clk);
		DFFD.clk(clk);
		
		DFFA.clr(clr);
		DFFB.clr(clr);
		DFFC.clr(clr);
		DFFD.clr(clr);
		
		SC_METHOD(shift);
		sensitive<<clk;
		//dont_initialize();
	}
};

#endif /* SHIFTREG_H_ */
