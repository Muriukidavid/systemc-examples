#include <systemc.h>
#include "four_bitshiftreg.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char* argv[])
{
	sc_signal<bool> s_din, s_dout, s_dff1dff2, s_dff2dff3, s_dff3dff4;
	sc_clock clock("clk",1,SC_NS,0.5);

	driver dr("driver");
	monitor mon("monitor");
	four_bitshiftreg four_bitshiftreg1("4bitshiftregister_instance_1");

	dr.d_din(s_din);
	four_bitshiftreg1.in_reg(s_din);
	mon.m_din(s_din);
	
	four_bitshiftreg1.outdff1(s_dff1dff2);
	mon.m_dff1dff2(s_dff1dff2);

	four_bitshiftreg1.outdff2(s_dff2dff3);
	mon.m_dff2dff3(s_dff2dff3);

	four_bitshiftreg1.outdff3(s_dff3dff4);
	mon.m_dff3dff4(s_dff3dff4);

	four_bitshiftreg1.outdff4(s_dout);
	mon.m_dout(s_dout);
	
	four_bitshiftreg1.regclock(clock);
	
	sc_trace_file *fp;
	fp=sc_create_vcd_trace_file("vcd_trace");
	fp->set_time_unit(1, SC_NS);

	sc_trace(fp, s_din, "D");
	sc_trace(fp, clock, "CLK");
	sc_trace(fp, s_dff1dff2, "Q1");
	sc_trace(fp, s_dff2dff3, "Q2");
	sc_trace(fp, s_dff3dff4, "Q3");
	sc_trace(fp, s_dout, "Q4");

	sc_start(20, SC_NS);
	sc_close_vcd_trace_file(fp);
	return 0;
}
