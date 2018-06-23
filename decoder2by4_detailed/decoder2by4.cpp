/*
 * decoder_2by4.cpp
 *
 *  Created on: May 22, 2018
 *      Author: ruthie
 */
#include "../decoder1by2/decoder_1by2.h"
#include "driver.h"
#include "andgate.h"
#include "monitor.h"
#include<systemc.h>
 
int sc_main(int argc, char *argv[]){
//some signals for interconnections

sc_signal<bool> ini,inj,in1,in2,in3,in4, out1, out2,out3,out4;
//modules instances
driver dr("driver");
and_gate and1("gate_instance_1");
and_gate and2("gate_instance_2");
and_gate and3("gate_instance_3");
and_gate and4("gate_instance_4");
decoder dec1_0("decoder");
decoder dec1_1("decoder_instance");

monitor mn("monitor");
//interconnections between modules
dr.d_a(ini);
dr.d_b(inj);

mn.m_a(ini);
mn.m_b(inj);

dec1_0.a(ini);
dec1_1.a(inj);

dec1_0.b(in1);
dec1_0.c(in2);
dec1_1.b(in3);
dec1_1.c(in4);


and1.a(in1);
and1.b(in3);
and1.c(out1);

and2.a(in1);
and2.b(in4);
and2.c(out2);

and3.a(in2);
and3.b(in3);
and3.c(out3);

and4.a(in2);
and4.b(in4);
and4.c(out4);

mn.m_c(out1);
mn.m_d(out2);
mn.m_e(out3);
mn.m_f(out4);


//create a trace file with nanosecond resolution
sc_trace_file *tf;//class trace instantiated with a pointer(stores the address of a variable)
tf = sc_create_vcd_trace_file("timing_diagram");
tf->set_time_unit(1, SC_NS);// signal sampled after every nano second
//trace the signals interconnecting modules
sc_trace(tf, ini, "binary_input1"); // signals to be traced
sc_trace(tf, inj, "binary_input2"); // signals to be traced
sc_trace(tf, out1, "output_1");
sc_trace(tf, out2, "output_2");
sc_trace(tf, out3, "output_3");
sc_trace(tf, out4, "outout_4");

//run a simulation for 20 systemc nano-seconds
if( !sc_pending_activity() )
sc_start(20,SC_NS);
//close the trace file
sc_close_vcd_trace_file(tf);
return 0;
}


