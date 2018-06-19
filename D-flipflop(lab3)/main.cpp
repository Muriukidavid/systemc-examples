#include <systemc.h>
#include "dff.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char* argv[])
{
	sc_clock clock("clk",5,SC_NS,0.5);
	sc_signal<bool> s1, s2, s3, s4, s5, s6;

	dff dff1("dff");
	driver dr("driver");
	monitor mon("monitor");

	dff1.clk(clock);

	dr.d_din(s1); // output
	dff1.din1(s1); // input
	dff1.din2(s1); // input

	dff1.dout1(s6); // output
	dff1.din3(s6); // input

	dff1.dout2(s2);	// output
	dff1.din7(s2); // input

	dff1.dout3(s3); // output
	dff1.din6(s3); // input

	dff1.dout5(s4); // output
	dff1.din4(s4); // input

	dff1.dout4(s5); // output
	dff1.din5(s5); // input

	mon.m_din(s1);
	mon.m_dout(s5);
	
	sc_trace_file *fp;
	fp=sc_create_vcd_trace_file("vcd_trace");
	fp->set_time_unit(1, SC_NS);

	//trace the signals interconnecting modules
	sc_trace(fp, clock, "clock"); // signals to be traced
	sc_trace(fp, s1, "input"); 
	sc_trace(fp, s5, "output");
	
	sc_start(20, SC_NS);
	sc_close_vcd_trace_file(fp);
	return 0;
}
