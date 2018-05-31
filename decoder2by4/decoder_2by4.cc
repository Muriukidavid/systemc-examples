/*
 * decoder_2by4.cc
 *
 *  Created on: Mar 4, 2016
 *      Author: karibe
 */
#include"../decoder1by2/decoder_1by2.h"
#include"driver.h"
#include"monitor.h"
#include"gate.h"
#include<systemc.h>

int sc_main(int argc, char *argv[]){
//some signals for interconnections
sc_signal<bool> in1, in2, out1, out2, out3, out4, sig1, sig2, sig3, sig4;
//module instances
decoder dec1("decoder_inst_1");
decoder dec2("decoder_inst_2");
driver dr("driver");
monitor mn("monitor");
gate gt1("gt_1");
gate gt2("gt_2");
gate gt3("gt_3");
gate gt4("gt_4");
//interconnections b2in modules
dr.d_a(in1);
dec1.a(in1);
mn.m_a(in1);

dr.d_b(in2);
dec2.a(in2);
mn.m_b(in2);

dec1.b(sig1);
dec1.c(sig2);

dec2.b(sig3);
dec2.c(sig4);

gt1.x(sig1);
gt1.y(sig3);
gt1.z(out1);
mn.m_w(out1);

gt2.x(sig1);
gt2.y(sig4);
gt2.z(out2);
mn.m_x(out2);

gt3.x(sig2);
gt3.y(sig3);
gt3.z(out3);
mn.m_y(out3);

gt4.x(sig2);
gt4.y(sig4);
gt4.z(out4);
mn.m_z(out4);

//create a trace file with nanosecond resolution
sc_trace_file *tf;
tf = sc_create_vcd_trace_file("timing_diagram");
tf->set_time_unit(1, SC_NS);
//trace the signals interconnecting modules
sc_trace(tf, in1, "binary_input1"); // signal to be traced
sc_trace(tf, in2, "binary_input2"); // signal to be traced
sc_trace(tf, out1, "output1");
sc_trace(tf, out2, "output2");
sc_trace(tf, out3, "output3");
sc_trace(tf, out4, "output4");
//run a simulation for 20 systemc nano-seconds
if( !sc_pending_activity() )
sc_start(20,SC_NS);
//close the trace file
sc_close_vcd_trace_file(tf);
return 0;
}
