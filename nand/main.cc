#include <systemc.h>
#include "driver.h"
#include "monitor.h"
#include "nand.h"

int sc_main(int argc, char* argv[]){
	
	// Test nand
	//ports and signals
	sc_signal<bool> s_A, s_B, s_out;
	
	//module instances
	nand_gate ng("nand_gate");
	driver dr("driver");
	monitor mon("monitor");
	
	//s_A
	ng.A(s_A);
	dr.d_A(s_A);
	mon.m_A(s_A);
	
	//s_B
	dr.d_B(s_B);
	ng.B(s_B);
	mon.m_B(s_B);
	
	//s_out
	ng.out(s_out);
	mon.m_out(s_out);
	
	//tracing
	sc_trace_file *fp;
	fp=sc_create_vcd_trace_file("vcd_trace");
	fp->set_time_unit(1, SC_NS);
	
	sc_trace(fp, s_A, "INPUT_A");
	sc_trace(fp, s_B, "INPUT_B");
	sc_trace(fp, s_out, "OUTPUT");
	
	//simulation start
	sc_start(20, SC_NS);
	sc_close_vcd_trace_file(fp);
	return 0; //end
}
