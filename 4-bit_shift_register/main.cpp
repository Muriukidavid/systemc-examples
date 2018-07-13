#include <systemc.h>
#include "register.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char* argv[])
{
	sc_signal<bool> s_din, s_dout,do_1,do_2,do_3;
	sc_clock clock("clk",5,SC_NS,0.5);

	regista rg("reg");
	driver dr("driver");
	monitor mon("monitor");

	dr.d_din(s_din);
	rg.d_in(s_din);
	mon.m_din(s_din);
	
	rg.d_out(s_dout);
	mon.m_dout(s_dout);

        mon.m_do1(do_1);
        mon.m_do2(do_2);
        mon.m_do3(do_3);
	
	rg.clock1(clock);
	
	sc_trace_file *fp;
	fp=sc_create_vcd_trace_file("vcd_trace");
	fp->set_time_unit(1, SC_NS);
//trace the signals interconnecting modules
        sc_trace(fp, clock, "clk");// signals to be traced
        sc_trace(fp, s_din, "D"); 
        sc_trace(fp, do_1, "Q1");
        sc_trace(fp, do_2, "Q2");
        sc_trace(fp, do_3, "Q3");
        sc_trace(fp, s_dout, "Q4");

	sc_start(20, SC_NS);
	sc_close_vcd_trace_file(fp);
	return 0;
}
