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
sc_signal<bool> in1,in2,out1, out2, out3, out4;
//module instances
decoder dec("decoder_instance");
driver dr("driver");
monitor mn("monitor");
//interconnections b2in modules
dr.d_a1(in1);
dec.a1(in1);
mn.m_a1(in1);

dr.d_a2(in2);
dec.a2(in2);
mn.m_a2(in2);

dec.b1(out1);
mn.m_b1(out1);

dec.b2(out2);
mn.m_b2(out2);

dec.b3(out3);
mn.m_b3(out3);

dec.b4(out4);
mn.m_b4(out4);

//create a trace file with nanosecond resolution
sc_trace_file *tf;
tf = sc_create_vcd_trace_file("timing_diagram");
tf->set_time_unit(1, SC_NS);
//trace the signals interconnecting modules
sc_trace(tf, in1, "input1");// signals to be traced
sc_trace(tf, in2, "input2");
sc_trace(tf, out1, "out1");// signals to be traced
sc_trace(tf, out2, "out2");
sc_trace(tf, out3, "out3");
sc_trace(tf, out4, "out4");

//run a simulation for 20 systemc nano-seconds
if( !sc_pending_activity() )
sc_start(25,SC_NS);
//close the trace file
sc_close_vcd_trace_file(tf);
return 0;
}



