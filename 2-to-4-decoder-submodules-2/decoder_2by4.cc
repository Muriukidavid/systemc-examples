#include"driver.h"
#include"inverter_operation.h"
#include"anding_operation.h"
#include"monitor.h"
#include<systemc.h>

int sc_main(int argc, char *argv[]){
	//some signals for interconnections
	sc_signal<bool> d_in1, d_in2, d_x, A1, A2, A3, A4, d_out1, d_out2, d_out3, d_out4;

	//class objects
	inverter inv("inverter_1");
	inverter inv2("inverter_2");
	driver dr("driver");
	monitor mn("monitor");
	anding_gate and_gate("anding_gate");

	
	/***********************************************
		Create interconnections b2in modules 
	************************************************/
	// driver object
	dr.d_A0(d_in1);
	dr.d_A1(d_in2);
	dr.d_x2(d_x);

	// inverter object 1
	inv.x1(d_in1);
	inv.m(d_x);
	inv.k(d_x);
	inv.out1(A1);
	inv.out2(A2);
	
	// inverter object 2
	inv2.x1(d_in2);
	inv2.m(d_x);
	inv2.k(d_x);
	inv2.out1(A3);
	inv2.out2(A4);
	
	// anding_gate object
	and_gate.g1_a(A1);
	and_gate.g1_b(A3);
	and_gate.g1_c(d_out1);

	and_gate.g2_a(A1);
	and_gate.g2_b(A4);
	and_gate.g2_c(d_out2);

	and_gate.g3_a(A2);
	and_gate.g3_b(A3);
	and_gate.g3_c(d_out3);

	and_gate.g4_a(A2);
	and_gate.g4_b(A4);
	and_gate.g4_c(d_out4);

	// monitor object
	mn.m0(d_x);
	mn.m1(d_in1);
	mn.m2(d_in2);
	mn.m3(d_out1);
	mn.m4(d_out2);
	mn.m5(d_out3);
	mn.m6(d_out4);

	/****************************************************
		End connection b2in modules
	****************************************************/

	//create a trace file with nanosecond resolution
	sc_trace_file *tf;
	tf = sc_create_vcd_trace_file("timing_diagram");
	tf->set_time_unit(1, SC_NS);
	
	//trace the signals interconnecting modules
	sc_trace(tf, d_x, "default_binary_input");	// signals to be traced
	sc_trace(tf, d_in1, "1st_binary_input"); 
	sc_trace(tf, d_in2, "2nd_binary_input");
	sc_trace(tf, d_out1, "d_out1");
	sc_trace(tf, d_out2, "d_out2");
	sc_trace(tf, d_out3, "d_out3");
	sc_trace(tf, d_out4, "d_out4");

	//run a simulation for 20 systemc nano-seconds
	if( !sc_pending_activity() )
	sc_start(25,SC_NS);
	
	//close the trace file
	sc_close_vcd_trace_file(tf);
	return 0;
}



