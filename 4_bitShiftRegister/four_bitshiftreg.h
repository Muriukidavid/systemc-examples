#include <systemc.h>
#include "dff.h"

SC_MODULE(four_bitshiftreg){
	sc_in <bool> in_reg, regclock;
	sc_out <bool> outdff1, outdff2, outdff3, outdff4; 
	sc_signal<bool> s_outdff1, s_outdff2, s_outdff3, s_outdff4,sin_reg;
	dff *dff1, *dff2, *dff3, *dff4;
	inverter *notgate;

	void four_bitshiftreg_func(void);
	void four_bitshiftreg_impl(void);
	~four_bitshiftreg();

	SC_CTOR(four_bitshiftreg){
		dff1 = new dff("dff_instance_1");
		dff2 = new dff("dff_instance_2");
		dff3 = new dff("dff_instance_3");
		dff4 = new dff("dff_instance_4");

		dff1->din(in_reg);
	
		dff1->dout(outdff1);
		dff2->din(outdff1);

		dff2->dout(outdff2);
		dff3->din(outdff2);

		dff3->dout(outdff3);
		dff4->din(outdff3);

		dff4->dout(outdff4);

		dff1->clk(regclock);
		dff2->clk(regclock);
		dff3->clk(regclock);
		dff4->clk(regclock);
		sensitive << regclock.pos();
		//sensitive<<dff1->clk.pos()<< dff2->clk.pos()<< dff3->clk.pos()<< dff4->clk.pos();

	}
};
