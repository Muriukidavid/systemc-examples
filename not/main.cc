#include <systemc.h>
//#include "dff.h"
#include "driver.h"
#include "monitor.h"
#include "notgate.h"

int sc_main(int argc, char* argv[]){
	/*
	 * Test not gate
	 *
	 */
	//signals
	sc_signal<bool> s_in, s_out;
	//module instances
	not_gate ng("not_gate");
	driver dr("driver");
	monitor mon("mon");
	//interconnects
	dr.d_din(s_in); //drive input
	ng.in(s_in);
	mon.m_din(s_in);
	
	ng.out(s_out);
	mon.m_s_out(s_out);
	
	
	//tracing
	sc_trace_file *fp;
	fp=sc_create_vcd_trace_file("vcd_trace");
	fp->set_time_unit(1, SC_SEC);
	
	sc_trace(fp, s_in, "INPUT");
	sc_trace(fp, s_out, "OUTPUT");
	
	//simulation start
	sc_start(20, SC_SEC);
	sc_close_vcd_trace_file(fp);
	return 0; //end
}
