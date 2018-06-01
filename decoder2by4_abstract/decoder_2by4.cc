/*
 * decoder_1by2.cc
 *
 *  Created on: Mar 4, 2016
 *      Author: karibe
 */
#include"decoder_2by4.h"
#include"driver.h"
#include"monitor.h"
#include<systemc.h>

int sc_main(int argc, char *argv[]){
//some signals for interconnections
sc_signal<bool> in_a, in_d, out1, out2, out3, out4;
//module instances
decoder dec("decoder_instance");
driver dr("driver");
monitor mn("monitor");

//interconnections b2in modules
dr.d_a(in_a);
dec.a(in_a);
mn.m_a(in_a);

dr.d_d(in_d);
dec.d(in_d);
mn.m_d(in_d);

dec.b(out1);
mn.m_b(out1);

dec.c(out2);
mn.m_c(out2);

dec.e(out3);
mn.m_e(out3);

dec.f(out4);
mn.m_f(out4);

//create a trace file with nanosecond resolution
sc_trace_file *tf;
tf = sc_create_vcd_trace_file("timing_diagram");
tf->set_time_unit(1, SC_NS);
//trace the signals interconnecting modules
sc_trace(tf, in_a, "binary_input_for_port_a"); // signals to be traced
sc_trace(tf, in_d, "binary_input_for_port_b");
sc_trace(tf, out1, "input_is_zero_for_both_a_and_b");
sc_trace(tf, out2, "input_is_zero_for_a_and_one_for_b");
sc_trace(tf, out3, "input_is_one_for_a_and_zero_for_b");
sc_trace(tf, out4, "input_is_one_for_both_a_and_b");


//run a simulation for 20 systemc nano-seconds
if( !sc_pending_activity() )
sc_start(25,SC_NS);
//close the trace file
sc_close_vcd_trace_file(tf);
return 0;
}



