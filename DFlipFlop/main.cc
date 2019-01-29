#include <systemc.h>
#include "dff.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char* argv[]){
	//ports and signals
	sc_signal<bool> s_din, s_dout, clear;
	sc_clock clock("clk",10,SC_NS,0.5,false);
	
	//module instances
	dff cell("D-flipflop");
	driver dr("driver");
	monitor mon("monitor");

	//clock
	cell.clk(clock);
	
	//clear
	cell.clr(clear);
	dr.d_clr(clear);
	mon.m_clr(clear);
	
	//s_din
	dr.d_din(s_din);
	cell.din(s_din);
	mon.m_din(s_din);
	
	//s_QA
	cell.dout(s_dout);
	mon.m_dout(s_dout);
	
	//tracing
	sc_trace_file *fp;
	fp=sc_create_vcd_trace_file("vcd_trace");
	fp->set_time_unit(100, SC_PS);
	
	sc_trace(fp, s_din, "INPUT");
	sc_trace(fp, clock, "CLK");
	sc_trace(fp, clear, "CLR");
	sc_trace(fp, s_dout, "OUTPUT");
	
	//simulation start
	sc_start(80, SC_NS);
	sc_close_vcd_trace_file(fp);
	return 0; //end
}
