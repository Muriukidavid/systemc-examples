#include <systemc.h>
#include "../DFlipFlop/dff.h"
#include "driver.h"
#include "monitor.h"
#include "shiftreg.h"

int sc_main(int argc, char* argv[])
{
	sc_signal<bool> s_din, s_QD, s_QA, s_QB, s_QC, clear;
	sc_clock klock("clk",10,SC_NS,0.5);

	shiftreg shifter("shift_register");
	driver dr("driver");
	monitor mon("monitor");

	//clock
	shifter.clk(klock);
	
	//clear
	shifter.clr(clear);
	dr.d_clr(clear);
	mon.m_clr(clear);
	
	//s_din
	dr.d_din(s_din);
	shifter.din(s_din);
	mon.m_din(s_din);
	
	//s_QA
	shifter.QA(s_QA);
	mon.m_QA(s_QA);
	//s_QB
	shifter.QB(s_QB);
	mon.m_QB(s_QB);
	//s_QC
	shifter.QC(s_QC);
	mon.m_QC(s_QC);
	//s_QD
	shifter.QD(s_QD);
	mon.m_QD(s_QD);	
	
	sc_trace_file *fp;
	fp=sc_create_vcd_trace_file("vcd_trace");
	fp->set_time_unit(100, SC_PS);
	
	sc_trace(fp, s_din, "D");
	sc_trace(fp, klock, "CLK");
	sc_trace(fp, clear, "CLR");
	sc_trace(fp, s_QA, "QA");
	sc_trace(fp, s_QB, "QB");
	sc_trace(fp, s_QC, "QC");
	sc_trace(fp, s_QD, "QD"); 
	
	sc_start(200, SC_NS);
	sc_close_vcd_trace_file(fp);
	return 0;
}
