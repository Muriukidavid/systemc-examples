#include <systemc.h>
#include "nand.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char* argv[])
{
	sc_signal<bool> s_A,s_B,s_F;
	

	nand nand1("nand");
	driver dr("driver");
	monitor mon("monitor");

	dr.d_A(s_A);
	nand1.A(s_A);
	mon.m_A(s_A);
	
	dr.d_B(s_B);
	nand1.B(s_B);
	mon.m_B(s_B);
	

	nand1.F(s_F);
	mon.m_F(s_F);
	

	
	
	sc_trace_file *fp;
	fp=sc_create_vcd_trace_file("vcd_trace");
	fp->set_time_unit(1, SC_NS);
	
	sc_trace(fp, s_A, "A");
	sc_trace(fp, s_B, "B");
	sc_trace(fp, s_F, "F");
	
	
	sc_start(60, SC_NS);
	sc_close_vcd_trace_file(fp);
	return 0;
}
