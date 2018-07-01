/*
 * decoder_2by4.cc
 *
 *  Created on: May 27, 2018
 *      Author: WBruss
 */
#include"decoder_2by4.h"
#include"driver.h"
#include"monitor.h"
#include<systemc.h>

int sc_main(int argc, char *argv[]){
//some signals for interconnections
sc_signal<bool> in1, in2, out1, out2, out3, out4;
//module instances
decoder2by4 dec2("decoder2by4cc");
driver dr("driver");
monitor mn("monitor");
//interconnections b2in modules
dr.d_a(in1);
dec2.dec_a(in1);
mn.m_o(in1);

dr.d_b(in2);
dec2.dec_b(in2);
mn.m_p(in2);

dec2.dec_m(out1);
mn.m_a(out1);

dec2.dec_n(out2);
mn.m_b(out2);

dec2.dec_o(out3);
mn.m_m(out3);

dec2.dec_p(out4);
mn.m_n(out4);

//create a trace file with nanosecond resolution
sc_trace_file *tf;
tf = sc_create_vcd_trace_file("timing_diagram");
tf->set_time_unit(1, SC_NS);
//trace the signals interconnecting modules
sc_trace(tf, in1, "binary_input1"); // signals to be traced
sc_trace(tf, in2, "binary_input2"); 

sc_trace(tf, out1, "Output1");
sc_trace(tf, out2, "Output2");
sc_trace(tf, out3, "Output3");
sc_trace(tf, out4, "Output4");

//run a simulation for 20 systemc nano-seconds
if( !sc_pending_activity() )
sc_start(20,SC_NS);
//close the trace file
sc_close_vcd_trace_file(tf);
return 0;
}
