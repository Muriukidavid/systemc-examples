#include <systemc.h>
#include "dff.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char* argv[])
{
	sc_clock clock("clk",5,SC_NS,0.5);
	sc_signal<bool> s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13;
	sc_signal<bool> x2, x3, x4, x5, x6, x9, x10, x11, x13;
	sc_signal<bool> y2, y3, y4, y5, y6, y9, y10, y11, y13;
	sc_signal<bool> z2, z3, z4, z5, z6, z9, z10, z11, z13;

	dff dff1("dff1");
	dff dff2("dff2");
	dff dff3("dff3");
	dff dff4("dff4");
	driver dr("driver");
	monitor mon("monitor");

	dff1.clk(clock);
	dff2.clk(clock);
	dff3.clk(clock);
	dff4.clk(clock);

	/********************************************************************
	// dff instance 1
	********************************************************************/
	dr.d_din(s1); // output

	dff1.din1(s1); // input
	dff1.din2(s1); // input
	
	dr.d_din1(s8);
	dff1.din9(s8);

	dr.d_din2(s12);
	dff1.din12(s12);

	dff1.dout1(s6); // output
	dff1.din3(s6); // input

	dff1.dout2(s2);	// output
	dff1.din7(s2); // input

	dff1.dout3(s3); // output
	dff1.din6(s3); // input

	dff1.dout5(s4); // output
	dff1.din4(s4); // input

	dff1.dout4(s5); // output
	dff1.din5(s5); // input
	dff1.din8(s5); // input
	
	dff1.dout6(s9); // output
	dff1.din10(s9); // input
	
	dff1.dout7(s13); // output
	
	dff1.dout8(s10); // output
	dff1.din11(s10); // input

	dff1.dout9(s11); // output
	dff1.din13(s11); // input


	/********************************************************************
	// dff instance 2
	********************************************************************/
	dff2.din1(s13);
	dff2.din2(s13);

	dff2.din9(s8);
	dff2.din12(s12);

	dff2.dout1(x6); 
	dff2.din3(x6);
 
	dff2.dout2(x2);	
	dff2.din7(x2);

	dff2.dout3(x3); 
	dff2.din6(x3); 

	dff2.dout5(x4); 
	dff2.din4(x4); 

	dff2.dout4(x5); 
	dff2.din5(x5); 
	dff2.din8(x5); 

	dff2.dout6(x9); 
	dff2.din10(x9);

	dff2.dout7(x13); 
	
	dff2.dout8(x10); 
	dff2.din11(x10); 

	dff2.dout9(x11);
	dff2.din13(x11); 

	/********************************************************************
	// dff instance 3
	********************************************************************/
	dff3.din1(x13);
	dff3.din2(x13);

	dff3.din9(s8);
	dff3.din12(s12);

	dff3.dout1(y6); 
	dff3.din3(y6);
 
	dff3.dout2(y2);	
	dff3.din7(y2);

	dff3.dout3(y3); 
	dff3.din6(y3); 

	dff3.dout5(y4); 
	dff3.din4(y4); 

	dff3.dout4(y5); 
	dff3.din5(y5); 
	dff3.din8(y5); 

	dff3.dout6(y9); 
	dff3.din10(y9);

	dff3.dout7(y13); 
	
	dff3.dout8(y10); 
	dff3.din11(y10); 

	dff3.dout9(y11);
	dff3.din13(y11); 

	/********************************************************************
	// dff instance 4
	********************************************************************/
	dff4.din1(y13);
	dff4.din2(y13);

	dff4.din9(s8);
	dff4.din12(s12);

	dff4.dout1(z6); 
	dff4.din3(z6);
 
	dff4.dout2(z2);	
	dff4.din7(z2);

	dff4.dout3(z3); 
	dff4.din6(z3); 

	dff4.dout5(z4); 
	dff4.din4(z4); 

	dff4.dout4(z5); 
	dff4.din5(z5); 
	dff4.din8(z5); 

	dff4.dout6(z9); 
	dff4.din10(z9);

	dff4.dout7(z13); 
	
	dff4.dout8(z10); 
	dff4.din11(z10); 

	dff4.dout9(z11);
	dff4.din13(z11); 


	mon.m_din(s1);
	mon.m_dout(s5);
	mon.m_dout2(s13);
	
	sc_trace_file *fp;
	fp=sc_create_vcd_trace_file("vcd_trace");
	fp->set_time_unit(1, SC_NS);

	//trace the signals interconnecting modules
	sc_trace(fp, clock, "clock"); // signals to be traced
	sc_trace(fp, s1, "D0"); 
	sc_trace(fp, s13, "QA");
	sc_trace(fp, x13, "QB");
	sc_trace(fp, y13, "QC");
	sc_trace(fp, z13, "QD");

	sc_start(80, SC_NS);
	sc_close_vcd_trace_file(fp);
	return 0;
}
