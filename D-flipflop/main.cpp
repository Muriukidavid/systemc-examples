#include <systemc.h>
#include "dff.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char* argv[])
{
	sc_signal<bool> s_din, s_dout, s_1, s_2, s_3;
	sc_clock clock("clk",5,SC_NS,0.5);

	dff dff1("dff");
	dff dff2("dff2");
	dff dff3("dff3");
	dff dff4("dff4");
	driver dr("driver");
	monitor mon("monitor");

	dr.d_din(s_din);	

	dff1.din(s_din);
	dff1.dout(s_1);
	dff2.din(s_1);
	dff2.dout(s_2);
	dff3.din(s_2);
	dff3.dout(s_3);
	dff4.din(s_3);
	dff4.dout(s_dout);

	mon.m_din(s_din);
	mon.m_1(s_1);
	mon.m_2(s_2);
	mon.m_3(s_3);
	mon.m_dout(s_dout);
	
	dff1.clk(clock);
	dff2.clk(clock);
	dff3.clk(clock);
	dff4.clk(clock);
	
	sc_trace_file *fp;
	fp=sc_create_vcd_trace_file("vcd_trace");
	fp->set_time_unit(1, SC_NS);

	sc_trace(fp, s_din, "Input(D)");
	sc_trace(fp, clock, "CLK");
	sc_trace(fp, s_1, "Output(Q1)");
	sc_trace(fp, s_2, "Output(Q2)");
	sc_trace(fp, s_3, "Output(Q3)");
	sc_trace(fp, s_dout, "Output(Q4)");

	sc_start(50, SC_NS);
	sc_close_vcd_trace_file(fp);
	return 0;
}
