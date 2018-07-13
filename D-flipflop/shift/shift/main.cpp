#include <systemc.h>
#include "dff.h"
#include "driver.h"
#include "monitor.h"
#include "shiftreg.h"

int sc_main(int argc, char* argv[])
{
	sc_signal<bool> s_din,sDin, s_QD,s_QA,s_QB,s_QC;
	sc_clock clock("clk",5,SC_NS,0.5);

	shiftreg shiftreg1("shiftreg");
	driver dr("driver");
	monitor mon("monitor");

	dr.d_din(s_din);
	shiftreg1.din(s_din);
	mon.m_din(s_din);
	

	shiftreg1.QA(s_QA);
	mon.m_QA(s_QA);
	
	shiftreg1.QB(s_QB);
	mon.m_QB(s_QB);
	
	shiftreg1.QC(s_QC);
	mon.m_QC(s_QC);
	
	shiftreg1.QD(s_QD);
	mon.m_QD(s_QD);
	
	shiftreg1.clk(clock);
	
	
	sc_trace_file *fp;
	fp=sc_create_vcd_trace_file("vcd_trace");
	fp->set_time_unit(1, SC_NS);
	
	sc_trace(fp, s_din, "D");
	sc_trace(fp, clock, "CLK");
	sc_trace(fp, s_QA, "QA");
	sc_trace(fp, s_QB, "QB");
	sc_trace(fp, s_QC, "QC");
	sc_trace(fp, s_QD, "QD"); 
	
	sc_start(60, SC_NS);
	sc_close_vcd_trace_file(fp);
	return 0;
}
