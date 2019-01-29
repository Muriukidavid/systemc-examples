#include "systemc.h"
#include "stimulus.h"
#include "exor2.h"
#include "mon.h"

int sc_main(int argc, char* argv[]){
	//signals
	sc_signal<bool> ASig, BSig, FSig;
	sc_clock TestClk("TestClock", 10, SC_NS,0.5);
	//modules and interconnects
	stim Stim1("Stimulus");
	Stim1.A(ASig);
	Stim1.B(BSig);
	Stim1.Clk(TestClk);
	//exor2
	exor2 DUT("exor2");
	DUT.A(ASig);
	DUT.B(BSig);
	DUT.F(FSig);
	//monitor
	mon Monitor1("Monitor");
	Monitor1.A(ASig);
	Monitor1.B(BSig);
	Monitor1.F(FSig);
	Monitor1.Clk(TestClk);
	//simulation start
	sc_start();  // run forever
	return 0;
}
