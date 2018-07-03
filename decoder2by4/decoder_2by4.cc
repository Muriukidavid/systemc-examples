
#include"decoder_1by2.h"
#include"driver.h"
#include"monitor.h"
#include<systemc.h>
#include"andgate.h"
int sc_main(int argc, char *argv[]){
//some signals for interconnections
sc_signal<bool> ina,inb, in1,in2,in3,in4, out1,out2,out3,out4;
//module instances
decoder dec1_1("decoder_1by2_1");
decoder dec1_2("decoder_1by2_2");
driver dr("driver");
monitor mn("monitor");
//andgates module
andgate andg_1("gate_instance_1");
andgate andg_2("gate_instance_2");
andgate andg_3("gate_instance_3");
andgate andg_4("gate_instance_4");
//interconnections b2in modules
dr.d_a(ina);
dr.d_b(inb);

mn.m_a(ina);
mn.m_b(inb);

dec1_1.a(ina);
dec1_2.a(inb);

dec1_1.b(in1);
dec1_1.c(in2);
dec1_2.b(in3);
dec1_2.c(in4);
//and gate
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

//monita
mn.m_e(out1);
mn.m_f(out2);
mn.m_g(out3);
mn.m_h(out4);



//create a trace file with nanosecond resolution
sc_trace_file *tf;
tf = sc_create_vcd_trace_file("timing_diagram");
tf->set_time_unit(1, SC_NS);
//trace the signals interconnecting modules
sc_trace(tf, in1, "input1"); // signals to be traced
sc_trace(tf, in2, "input2");
sc_trace(tf, out1, "out1");
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



