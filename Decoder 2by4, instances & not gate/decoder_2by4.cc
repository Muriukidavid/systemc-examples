#include<systemc.h>

#include"decoder_2by4.h"
#include"inverter.h"
#include"driver.h"
#include"monitor.h"
#include "AND_Gate.h"

int sc_main(int argc, char *argv[]){
	//some signals for interconnections
	sc_signal<bool> d_in1, d_in2, A1, A2, A3, A4, d_out1, d_out2, d_out3, d_out4;

	//module instances
	decoder dec("decoder_Instance1");
	decoder dec2("decoder_Instance2");
	driver dr("driver");
	monitor mn("monitor");
	anding_gate AndGate("anding_gate");

	
	/*
	 *The interconnections between the modules
	 */

	// driver connections
	dr.d_a(d_in1);
	dr.d_b(d_in2);

	// decoder instance 1
	dec.in(d_in1);
	dec.out1(A1);
	dec.out2(A2);

	// decoder instance 2
	dec2.in(d_in2);
	dec2.out1(A3);
	dec2.out2(A4);

	// anding_gate Connections
	AndGate.g1_a(A1);
	AndGate.g1_b(A3);
	AndGate.g1_result(d_out1);

	AndGate.g2_a(A1);
	AndGate.g2_b(A4);
	AndGate.g2_result(d_out2);

	AndGate.g3_a(A2);
	AndGate.g3_b(A3);
	AndGate.g3_result(d_out3);

	AndGate.g4_a(A2);
	AndGate.g4_b(A4);
	AndGate.g4_result(d_out4);

	// monitor connections
	mn.m1(d_in1);
	mn.m2(d_in2);
	mn.m3(d_out1);
	mn.m4(d_out2);
	mn.m5(d_out3);
	mn.m6(d_out4);

	/*
	 * End of connection between modules
	 */

	//create a trace file with nanosecond resolution
	sc_trace_file *tf;
	tf = sc_create_vcd_trace_file("timing_diagram");
	tf->set_time_unit(1, SC_NS);
	
	//trace the signals interconnecting modules
	sc_trace(tf, d_in1, "1st_input"); // signals to be traced
	sc_trace(tf, d_in2, "2nd_input");
	sc_trace(tf, d_out1, "output_1");
	sc_trace(tf, d_out2, "output_2");
	sc_trace(tf, d_out3, "output_3");
	sc_trace(tf, d_out4, "output_4");

	//run a simulation for 20 systemc nano-seconds
	if( !sc_pending_activity() )
	sc_start(25,SC_NS);
	
	//close the trace file
	sc_close_vcd_trace_file(tf);
	return 0;
}




