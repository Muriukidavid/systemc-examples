#include <systemc.h>
#include "dff.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char* argv[])
{
	sc_signal<bool> s_din, sig1, sig2, sig3, s_dout;
	sc_clock clock("clk",5,SC_PS,0.5);

	dff dff1("dff_instance_1");
	dff dff2("dff_instance_2");
	dff dff3("dff_instance_3");
	dff dff4("dff_instance_4");
	driver dr("driver");
	monitor mon("monitor");

	dr.d_din(s_din);
	dff1.din(s_din);
	mon.m_din(s_din);
	
	dff1.dout(sig1);
	dff2.din(sig1);
	mon.m_a(sig1);

	dff2.dout(sig2);
	dff3.din(sig2);
	mon.m_b(sig2);

	dff3.dout(sig3);
	dff4.din(sig3);
	mon.m_c(sig3);

	dff4.dout(s_dout);
	mon.m_dout(s_dout);
	
	dff1.clk(clock);
	dff2.clk(clock);
	dff3.clk(clock);
	dff4.clk(clock);
	
	sc_trace_file *fp;
	fp=sc_create_vcd_trace_file("vcd_trace");
	fp->set_time_unit(1, SC_PS);

	sc_trace(fp, s_din, "D");
	sc_trace(fp, clock, "CLK");
	sc_trace(fp, sig1, "Q1");
	sc_trace(fp, sig2, "Q2");
	sc_trace(fp, sig3, "Q3");
	sc_trace(fp, s_dout, "Q4");

	sc_start(60, SC_PS);
	sc_close_vcd_trace_file(fp);
	return 0;
}
