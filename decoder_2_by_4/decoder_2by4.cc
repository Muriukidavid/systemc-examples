#include"decoder_2by4.h"
#include"driver.h"
#include"monitor.h"
#include<systemc.h>


int sc_main(int argc, char *argv[]){
	//some signals for interconnections
	sc_signal<bool> in_A0, in_A1, out_D0, out_D1, out_D2, out_D3;
	
	//module instances
	decoder dec("decoder_instance");
	driver dr("driver");
	monitor mn("monitor");
	
	//interconnections b2in modules
	dr.d_A0(in_A0);	
	dec.A0(in_A0);
	mn.m_A0(in_A0);

	dr.d_A1(in_A1);
	dec.A1(in_A1);
	mn.m_A1(in_A1);

	dec.D0(out_D0);
	mn.m_D0(out_D0);

	dec.D1(out_D1);
	mn.m_D1(out_D1);

	dec.D2(out_D2);
	mn.m_D2(out_D2);

	dec.D3(out_D3);
	mn.m_D3(out_D3);


	//create a trace file with nanosecond resolution
	sc_trace_file *tf;
	tf = sc_create_vcd_trace_file("timing_diagram");
	tf->set_time_unit(1, SC_NS);
	
	//trace the signals interconnecting modules
	sc_trace(tf, in_A0, "binary_input_A0");	// signal to be traced
	sc_trace(tf, in_A1, "binary_input_A1");	// signal to be traced
	sc_trace(tf, out_D0, "A0_as_0_&_A1_as_0");
	sc_trace(tf, out_D1, "A0_as_1_&_A1_as_0");
	sc_trace(tf, out_D2, "A0_as_0_&_A1_as_1");
	sc_trace(tf, out_D3, "A0_as_1_&_A1_as_1");

	//run a simulation for 20 systemc nano-seconds
	if( !sc_pending_activity() )
	sc_start(25,SC_NS);
	
	//close the trace file
	sc_close_vcd_trace_file(tf);
	
	return 0;
}



