/*
 * decoder_1by2.cc
 *
 *  Created on: Mar 4, 2016
 *      Author: karibe
 */
//#include"decoder_1by2.h"
//#include"driver.h"
//#include"andgate.h"
#include<systemc.h>
#include"decoder_2by4.h"
#include"monitor.h"
#include"driver.h"

int sc_main(int argc, char *argv[]){
//some signals for interconnections

sc_signal<bool> in_m,in_n,out_q, out_r,out_s,out_t;
//module instances
decoder2by4 dec2by4("decoder_2by4_instance");
driver dr("driver_two_by_four");
monitor mn("monitor_two_by_four");

//interconnections b2in modules
dr.d_m(in_m);
mn.m_m(in_m);
dec2by4.m(in_m);

dr.d_n(in_n);
mn.m_n(in_n);
dec2by4.n(in_n);

dec2by4.q(out_q);
mn.m_q(dec2by4.q);
dec2by4.r(out_r);
mn.m_r(dec2by4.r);
dec2by4.s(out_s);
mn.m_s(dec2by4.s);
dec2by4.t(out_t);
mn.m_t(dec2by4.t);

//create a trace file with nanosecond resolution
sc_trace_file *tf;
tf = sc_create_vcd_trace_file("timing_diagram");
tf->set_time_unit(1, SC_NS);
//trace the signals interconnecting modules
sc_trace(tf, in_m, "binary_input_for_port_m"); // signals to be traced
sc_trace(tf, in_n, "binary_input_for_port_n");
sc_trace(tf, out_q, "binary_output_for_port_q");
sc_trace(tf, out_r, "binary_output_for_port_r");
sc_trace(tf, out_s, "binary_output_for_port_s");
sc_trace(tf, out_t, "binary_output_for_port_t");


//run a simulation for 20 systemc nano-seconds
if( !sc_pending_activity() )
sc_start(25,SC_NS);
//close the trace file
sc_close_vcd_trace_file(tf);
return 0;
}



