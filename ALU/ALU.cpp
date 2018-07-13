#include "systemc.h"
#include "driver.h"
#include "ALU.h"
#include "mon.h"

int sc_main(int argc, char* argv[]) {   
	sc_signal < sc_uint<8> > A,B,F;   
	sc_signal < sc_uint<4> > O;
	sc_signal <bool> zero;
	sc_clock TestClk("TestClock", 10, SC_NS,1,SC_NS);

	driver Stim1("Data");   
	Stim1.opA(A);   
	Stim1.opB(B);
	Stim1.op(O);
	Stim1.Clk(TestClk);

	alu A1("A");
	A1.opA(A);
	A1.opB(B);
	A1.op(O);
	A1.result(F);
	A1.zero(zero);

  	mon Monitor1("Monitor");   
	Monitor1.opA(A);   
	Monitor1.opB(B);   
	Monitor1.op(O);
	Monitor1.result(F);
	Monitor1.Clk(TestClk);   
	Monitor1.zero(zero);
    
sc_trace_file *fp;
	fp=sc_create_vcd_trace_file("vcd_trace");
	fp->set_time_unit(1, SC_NS);
    sc_trace(fp, A, "input");
    sc_trace(fp, B, "input");
    sc_trace(fp, F, "output");
    sc_trace(fp, O, "operation");
    
	sc_start(200, SC_NS);
	sc_close_vcd_trace_file(fp);
	return 0;
}

	
	
