#include <systemc.h>
#include "notgate.h"
#include "driver.h"
#include "monitor.h"


int sc_main(int argc, char* argv[])
{
	sc_signal<bool> s_in,s_out;
	

	not_gate not_gate1("notgate");
	driver dr("driver");
	monitor mon("monitor");

	dr.d_in(s_in);
	not_gate1.in(s_in);
	mon.m_in(s_in);
	

	not_gate1.out(s_out);
	mon.m_out(s_out);
	
	
	
	sc_trace_file *fp;
	fp=sc_create_vcd_trace_file("vcd_trace");
	fp->set_time_unit(1, SC_NS);
	
	sc_trace(fp, s_in, "in");
	sc_trace(fp, s_out, "out");
	 
	
	sc_start(60, SC_NS);
	sc_close_vcd_trace_file(fp);
	return 0;
}
