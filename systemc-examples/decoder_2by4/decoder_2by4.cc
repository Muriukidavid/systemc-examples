//#include"decoder_1by2.h"	
#include"decoder_2by4.h"
#include"driver.h"
#include"monitor.h"
#include<systemc.h>

int sc_main(int argc, char *argv[]){


//some signals for interconnections
sc_signal<bool> drive_a,drive_b,mon_c,mon_d,mon_e,mon_f;
//module instances
driver dr("drive");
monitor mn("monita");
decoder_2by4 dec("decoder_instance");

//interconnections b2in modules
//drive_a
dr.d_a(drive_a);
dec.in1(drive_a);
mn.m_a(drive_a);

//drive_b
dr.d_b(drive_b);
dec.in2(drive_b);
mn.m_b(drive_b);

//mon_c
dec.d_out1(mon_c);
mn.m_c(mon_c);

//mon_d
dec.d_out2(mon_d);
mn.m_d(mon_d);

//mon_e
dec.d_out1(mon_e);
mn.m_e(mon_e);

//mon_f
dec.d_out2(mon_f);
mn.m_f(mon_f);


//create a trace file with nanosecond resolution
sc_trace_file *tf;
tf = sc_create_vcd_trace_file("timing_diagram");
tf->set_time_unit(1, SC_NS);
//trace the signals interconnecting modules
sc_trace(tf, drive_a, "output_1"); 
sc_trace(tf, drive_b, "output_2"); 
sc_trace(tf, mon_c, "input1_00b");
sc_trace(tf, mon_d, "input1_01b");
sc_trace(tf, mon_e, "input1_10b");
sc_trace(tf, mon_f, "input1_11b");

//run a simulation for 20 systemc nano-seconds
if( !sc_pending_activity() )
sc_start(50,SC_NS);
sc_close_vcd_trace_file(tf);

return 0;
}
};





































































































































































































































































