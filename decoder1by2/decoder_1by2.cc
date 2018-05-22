/*
 * decoder_1by2.cc
 *
 *  Created on: Mar 4, 2016
 *      Author: karibe
 */
#include"decoder_1by2.h"
#include"decoder_2by4.h"
#include"driver.h"
#include"monitor.h"
#include<systemc.h>

int sc_main(int argc, char *argv[]){
//some signals for interconnections
sc_signal<bool> in1, in2, inout1, inout2, mid1, mid2, mid3, mid4, out1, out2, out3,out4;
//module instances
decoder dec_2("decoder_2");
decoder dec_1("decoder_1");
driver dr("driver");
monitor mn("monitor");
decoder2 dec2("decoder2");
//interconnections b2in modules
dr.d_a(in1);
dr.d_b(in2);

dec_1.a(in1);
dec_2.a(in2);

dec_1.b(mid1);
dec_2.b(mid3);

dec_1.c(inout1);
dec_2.c(inout2);

dec2.w(mid1);
dec2.z(mid3);
dec2.x(inout1);
dec2.y(inout2);

dec2.o(out1);
dec2.p(out4);
dec2.q(out3);
dec2.r(out2);

mn.m_a(out1);
mn.m_b(out3);
mn.m_c(out4);
mn.m_d(out2);

mn.m_e(in1);
mn.m_f(in2);

//create a trace file with nanosecond resolution
sc_trace_file *tf;
tf = sc_create_vcd_trace_file("timing_diagram");
tf->set_time_unit(1, SC_NS);
//trace the signals interconnecting modules
sc_trace(tf, in1, "binary_input1"); // signals to be traced
sc_trace(tf, in2, "binary_input2");
sc_trace(tf, out1, "Output_1");
sc_trace(tf, out3, "Output_2");
sc_trace(tf, out4, "Output_3");
sc_trace(tf, out2, "Output_4");

//run a simulation for 20 systemc nano-seconds
if( !sc_pending_activity() )
sc_start(20,SC_NS);
//close the trace file
sc_close_vcd_trace_file(tf);
return 0;
}



