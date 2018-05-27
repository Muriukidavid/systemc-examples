/*
 * decoder_2by4.cc
 *
 *  Created on: May 27, 2018
 *      Author: WBruss
 */
#include"../decoder1by2/decoder_1by2.h"
#include"andgate.h"
#include"driver.h"
#include"monitor.h"
#include<systemc.h>

int sc_main(int argc, char *argv[]){
//some signals for interconnections
sc_signal<bool> in1, in2, mid1, mid2, mid3, mid4, out1, out2, out3, out4;
//module instances
decoder dec_1("decoder_instance1");
decoder dec_2("decoder_instance2");
andgate and_1("and_1");
andgate and_2("and_2");
andgate and_3("and_3");
andgate and_4("and_4");
driver dr("driver");
monitor mn("monitor");
//interconnections b2in modules
dr.d_a(in1);
dr.d_b(in2);

dec_1.a(in2);
dec_2.a(in1);

dec_1.b(mid1);
dec_2.b(mid3);

dec_1.c(mid2);
dec_2.c(mid4);

and_1.x(mid1);
and_2.x(mid1);
and_3.x(mid2);
and_4.x(mid2);

and_1.y(mid3);
and_2.y(mid4);
and_3.y(mid3);
and_4.y(mid4);

and_1.z(out1);
and_2.z(out2);
and_3.z(out3);
and_4.z(out4);

mn.m_a(out1);
mn.m_b(out2);
mn.m_c(out3);
mn.m_d(out4);

mn.m_e(in1);
mn.m_f(in2);

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



