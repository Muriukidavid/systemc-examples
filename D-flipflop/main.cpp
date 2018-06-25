#include <systemc.h>
#include "dff.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char* argv[])
{
	sc_signal<bool> s_din, s_dout, signal1, signal2, signal3;
	sc_clock clock("clk",5,SC_PS,0.5);

	dff dff1("dff");
	dff dff2("dff_instance2");
	dff dff3("dff_instance3");
	dff dff4("dff_instance4");

	driver dr("driver");
	monitor mon("monitor");

	dr.d_din(s_din);
	dff1.din(s_din);
	mon.m_din(s_din);
	
	dff4.dout(s_dout);
	mon.m_dout(s_dout);

	dff3.dout(signal3);
	dff4.din(signal3);
	mon.m_d3(signal3);

	dff2.dout(signal2);
	dff3.din(signal2);
	mon.m_d2(signal2);

	dff1.dout(signal1);
	dff2.din(signal1);
	mon.m_d1(signal1);
	
	dff1.clk(clock);
	dff2.clk(clock);
	dff3.clk(clock);
	dff4.clk(clock);
	
	sc_trace_file *fp;
	fp=sc_create_vcd_trace_file("vcd_trace");
	fp->set_time_unit(1, SC_PS);

	sc_trace(fp, s_din, "Input(D)");
	sc_trace(fp, clock, "CLK");
	sc_trace(fp, signal1, "Output(Q1)");
	sc_trace(fp, signal2, "Output(Q2)");
	sc_trace(fp, signal3, "Output(Q3)");
	sc_trace(fp, s_dout, "Output(Q4)");

	sc_start(30, SC_PS);
	sc_close_vcd_trace_file(fp);
	return 0;
}
