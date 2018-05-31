/*
 * decoder_2by4.cc
 *
 *  Created on: may 23, 2018
 *      Author: ruth ndunge
 */
#include"decoder_1by2.h"
#include"driver.h"
#include"andgate.h"
#include"monitor.h"
#include<systemc.h>

int sc_main(int argc, char *argv[]){
//some signals for interconnections

sc_signal<bool> inx,iny,in1,in2,in3,in4, out1, out2,out3,out4;
//module instances
//decoder2 dec2("decoder_instance");
driver dr("driver2b4");
//and_gate andg_0("gate_instance_0");

and_gate andg_1("gate_instance_1");
and_gate andg_2("gate_instance_2");
and_gate andg_3("gate_instance_3");
and_gate andg_4("gate_instance_4");


decoder dec1_0("decoder_1by2_0");
decoder dec1_1("decoder_1by2_1");

monitor mn("monitor");
//interconnections in modules
dr.d_a(inx);
dr.d_b(iny);

mn.m_a(inx);
mn.m_b(iny);

dec1_0.a(inx);
dec1_1.a(iny);

dec1_0.b(in1);
dec1_0.c(in2);
dec1_1.b(in3);
dec1_1.c(in4);



andg_1.a(in1);
andg_1.b(in3);
andg_1.c(out1);

andg_2.a(in1);
andg_2.b(in4);
andg_2.c(out2);

andg_3.a(in2);
andg_3.b(in3);
andg_3.c(out3);

andg_4.a(in2);
andg_4.b(in4);
andg_4.c(out4);



mn.m_e(out1);
mn.m_f(out2);
mn.m_g(out3);
mn.m_h(out4);



//create a trace file with nanosecond resolution
sc_trace_file *tf;
tf = sc_create_vcd_trace_file("timing_diagram");
tf->set_time_unit(1, SC_NS);
//trace the signals interconnecting modules
sc_trace(tf, inx, "binary_input1"); // signals to be traced
sc_trace(tf, iny, "binary_input2"); // signals to be traced
sc_trace(tf, out1, "out1");
sc_trace(tf, out2, "out2");
sc_trace(tf, out3, "out3");
sc_trace(tf, out4, "out4");

//run a simulation for 20 systemc nano-seconds
if( !sc_pending_activity() )
sc_start(20,SC_NS);
//close the trace file
cout<<"argv[1]: "<<atoi(argv[1])<<endl;
sc_close_vcd_trace_file(tf);
return 0;
}













