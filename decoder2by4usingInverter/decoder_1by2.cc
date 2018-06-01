/*
 * decoder_1by2.cc
 *
 *  Created on: Mar 4, 2016
 *      Author: karibe
 */
#include"decoder_1by2.h"
#include"driver.h"
#include"monitor.h"
#include<systemc.h>

int sc_main(int argc, char *argv[]){
//some signals for interconnections
sc_signal<bool> in1, in2, out1, out2, out3, out4, final_out1, final_out2, final_out3, final_out4;
//module instances
decoder dec("decoder_instance_1");
decoder dec2("decoder_instance_2");
driver dr("driver");

a_gate gate1("a_gate_instance_1");
a_gate gate2("a_gate_instance_2");
a_gate gate3("a_gate_instance_3");
a_gate gate4("a_gate_instance_4");
monitor mn("monitor");

//interconnections b2in modules
//connecting driver ports to signals
dr.d_a(in1);
dr.d_b(in2);

//connecting first decoder ports to signals 
dec.a(in1);
mn.m_a(in1);

dec.b(out1);
mn.m_b(final_out1);

dec.c(out2);
mn.m_c(final_out2); 

//conncecting second decoder ports to signals 
dec2.a(in2);
mn.m_d(in2);

dec2.b(out3);
mn.m_e(final_out3);

dec2.c(out4);
mn.m_f(final_out4);

//connecting first andgate ports to signals
gate1.a(out1);
gate1.b(out3);
gate1.c(final_out1);

//connecting second andgate ports to signals
gate2.a(out1);
gate2.b(out4);
gate2.c(final_out2);

//connecting third andgate ports to signals
gate3.a(out2);
gate3.b(out3);
gate3.c(final_out3);

//connecting fourth andgate ports to signals
gate4.a(out2);
gate4.b(out4);
gate4.c(final_out4);

//create a trace file with nanosecond resolution
sc_trace_file *tf;
tf = sc_create_vcd_trace_file("timing_diagram");
tf->set_time_unit(1, SC_NS);
//trace the signals interconnecting modules
sc_trace(tf, in1, "binary_input"); // first decoder signals to be traced
sc_trace(tf, final_out1, "input_is_00");
sc_trace(tf, final_out2, "input_is_01");

sc_trace(tf, in2, "binary_input_2"); // second decoder signals to be traced
sc_trace(tf, final_out3, "input_is_10");
sc_trace(tf, final_out4, "input_is_11");

//run a simulation for 20 systemc nano-seconds
if( !sc_pending_activity() )
sc_start(25,SC_NS);
//close the trace file
sc_close_vcd_trace_file(tf);
return 0;
}




