#include"decoder2by4.h"
#include"driver.h"
#include"monitor.h"
#include<systemc.h>

int sc_main(int argc, char *argv[]){
//some signals for interconnections
sc_signal<bool>drive_a,drive_b,mon_c,mon_d,mon_e,mon_f;
//module instances
decoder dec("decoder_instance");
driver dr("driver");
monitor mn("monitor");
//interconnections b2in modules
dr.d_a(drive_a);
dec.a(drive_a);
mn.m_a(drive_a);

dr.d_b(drive_b);
dec.b(drive_b);
mn.m_b(drive_b);

dec.c(mon_c);
mn.m_c(mon_c);

dec.d(mon_d);
mn.m_d(mon_d);

dec.e(mon_e);
mn.m_e(mon_e);

dec.f(mon_f);
mn.m_f(mon_f);

//create a trace file with nanosecond resolution
sc_trace_file *tf;
tf = sc_create_vcd_trace_file("timing_diagram");
tf->set_time_unit(1, SC_NS);
//trace the signals interconnecting modules
sc_trace(tf, drive_a, "binary_input1"); // signals to be traced
sc_trace(tf, drive_b, "binary_input2");
sc_trace(tf, mon_c, "input_is_00 ");
sc_trace(tf, mon_d, "input1_is_01");
sc_trace(tf, mon_e, "input1_is_10 ");
sc_trace(tf, mon_f, "input1_is_11 ");

//run a simulation for 20 systemc nano-seconds
if( !sc_pending_activity() )
sc_start(25,SC_NS);
//close the trace file
sc_close_vcd_trace_file(tf);
return 0;
}

