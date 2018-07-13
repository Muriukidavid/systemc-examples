#ifndef SHIFTREG_H_
#define SHIFTREG_H_
#include <systemc.h>
#include "../DFlipFlop/dff.h"

SC_MODULE (shiftreg) {

	sc_in <bool> clk, clr, din;
	sc_out <bool> QA, QB, QC, QD;
	
	
	dff DFFA, DFFB, DFFC, DFFD;
	
   	sc_signal<bool> s_QA, s_QB, s_QC,  s_QD , sDin, clock, clear;
	SC_CTOR(shiftreg) :DFFA("dffa"),DFFB("dffb"),DFFC("dffc"),DFFD("dffd") {
		
		
		//input
		
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
		
		DFFA.clk(clock);
		DFFB.clk(clock);
		DFFC.clk(clock);
		DFFD.clk(clock);
		
		DFFA.clr(clear);
		DFFB.clr(clear);
		DFFC.clr(clear);
		DFFD.clr(clear);
		
		SC_METHOD (shiftreg_method);
	}
	void shiftreg_method(void);
	

};

#endif /* SHIFTREG_H_ */
