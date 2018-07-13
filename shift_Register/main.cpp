#include <systemc.h>
#include "driver.h"
#include "monitor.h"
#include "shiftR.h"



int sc_main(int argc, char* argv[])
{
    sc_in <bool> reg_in;
	sc_signal<bool> s_din, s_dout, QA, QB, QC, QD;
	sc_clock clock("clk",5,SC_NS,0.5);

	dff dff1("dff");
	driver dr("driver");
	monitor mon("monitor");
    shiftR shiftReg("shift_register");

	dr.d_din(s_din);
    dff1.din(s_din);
	mon.m_din(s_din);
    shiftReg.reg_in(s_din);
	
	dff1.dout(s_dout);
	mon.m_dout(s_dout);
    mon.m_A(QA);
    mon.m_B(QB);
    mon.m_C(QC);
    mon.m_D(QD);
	
	dff1.clk(clock);
	
	sc_trace_file *fp;
	fp=sc_create_vcd_trace_file("vcd_trace");
	fp->set_time_unit(1, SC_NS);
    sc_trace(fp, s_din, "Input_Signal");
    sc_trace(fp, s_dout, "Output_Signal");
	sc_start(20, SC_NS);
	sc_close_vcd_trace_file(fp);
	return 0;
}
