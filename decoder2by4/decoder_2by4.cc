/*
 * decoder_2by4.cc
 *
 *  Created on: May 23, 2018
 *      Author: ruth ndunge
 */
#include"decoder_2by4.h"
#include"driver.h"
#include"monitor.h"
#include<systemc.h>

int sc_main(int argc, char *argv[]){

//some signals for interconnections
sc_signal<bool> in1, in2, out1, out2, out3, out4;

//module instances
decoder dec("decoder_instance");
driver dr("driver");
monitor mn("monitor");

//interconnections b2in modules
dr.d_a(in1);
dec.a(in1);
mn.m_a(in1);

dr.d_b(in2);
dec.b(in2);
mn.m_b(in2);

dec.c(out1);
mn.m_c(out1);

dec.d(out2);
mn.m_d(out2);

dec.e(out3);
mn.m_e(out3);

dec.f(out4);
mn.m_f(out4);

//create a trace file with nanosecond resolution
sc_trace_file *tf;
tf = sc_create_vcd_trace_file("timing_diagram");
tf->set_time_unit(1, SC_NS);

//trace the signals interconnecting modules
sc_trace(tf, in1, "binary_input1"); // signals to be traced
sc_trace(tf, in2, "binary_input2");
sc_trace(tf, out1, "output_1");
sc_trace(tf, out2, "output_2");
sc_trace(tf, out3, "output_3");
sc_trace(tf, out4, "output_4");

//Output table header
cout<<"\n\nTime Input1 Input2 \t Out1 \t Out2 \t Out3 \t Out4"<<endl;

//run a simulation for 20 systemc nano-seconds
if( !sc_pending_activity() )
sc_start(20,SC_NS);
//close the trace file
sc_close_vcd_trace_file(tf);
return 0;
}



