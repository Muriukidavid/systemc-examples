#include <systemc.h>
#include "dff.h"
#include "driver.h"
#include "monitor.h"
#include "NandGate.h"

int sc_main(int argc, char* argv[])
{
	sc_signal<bool> s_din, s_dout, s_dff1, s_dff2, s2_dout;
	sc_clock clock("clk",5,SC_NS,0.5);
	//module instances
	dff dff1("dff");
	driver dr("driver");
	monitor mon("monitor");

	//interconnections b2in modules
	dr.d_din(s_din);
	dff1.S(s_din);
	mon.m_din(s_din);
	dff1.Q(s_dout);
	mon.m2_din(s2_dout);

	dff1.R(clock);
	
	//Monitor inputs
	mon.m_din(s_dout);
	mon.m2_din(s2_dout);


	/*
	 * Additional module & interconnections between the modules
	 */

//	//First column AND gates inputs
//	dff1.dinA(s_din);
//	dff1.clk_A(clock);
//	dff1.dinB(s_din);
//	dff1.clk_B(clock);
//
//	dff1.doutA(s_dff1);  //Their output signals.
//	dff1.doutB(s_dff2);
//
//	//Second column AND gates: connect ports directly
//	dff1.dinC(s_dff1);
//	dff1.toggleC(s2_dout);
//	dff1.toggleD(s_dout);
//	dff1.dinD(s_dff2);
//
//	dff1.doutC(s_dout);  // the outputs
//	dff1.doutD(s2_dout);

	//The trace signals
	sc_trace_file *fp;
	fp=sc_create_vcd_trace_file("vcd_trace");
	fp->set_time_unit(1, SC_NS);

	/*
	 *  The signals to be traced
	 */

	sc_trace(fp, s_dout, "Signal one output");
	sc_trace(fp, s2_dout, "Signal two output");
	sc_trace(fp, clock, "The clock signal");

	/*
	 * Start and close of the signal trace
	 *
	 */

	sc_start(20, SC_NS);
	sc_close_vcd_trace_file(fp);
	return 0;
}
