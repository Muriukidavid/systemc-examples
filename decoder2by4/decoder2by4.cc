#include "decoder2by4.h"
#include "driver.h"
#include "monitor.h"

int sc_main(int argc, char* argv[]){
	//signals
	sc_signal<bool> drive_a, drive_b, mon_c, mon_d, mon_e, mon_f;
	//module instances
	driver dr("driver_instance");
	monitor mn("monitor_instance");
	decoder2by4 decoder("decoder_instance");

	//interconnections
	//drive_a
	dr.d_a(drive_a);
	decoder.d_in1(drive_a);
	mn.m_a(drive_a);
	//drive_b
	dr.d_b(drive_b);
	decoder.d_in2(drive_b);
	mn.m_b(drive_b);
	//mon_c
	decoder.d_out1(mon_c);
	mn.m_c(mon_c);
	//mon_d
	decoder.d_out2(mon_d);
	mn.m_d(mon_d);
	//mon_e
	decoder.d_out3(mon_e);
	mn.m_e(mon_e);
	//mon_f
	decoder.d_out4(mon_f);
	mn.m_f(mon_f);
	//create a trace file with nanosecond resolution
	sc_trace_file *tf;
	tf = sc_create_vcd_trace_file("timing_diagram");
	tf->set_time_unit(1, SC_NS);
	//trace the signals interconnecting modules
	sc_trace(tf, drive_a, "driver_output_a"); // signals to be traced
	sc_trace(tf, drive_b, "driver_output_b");
	sc_trace(tf, mon_c, "input_is_00b");
	sc_trace(tf, mon_d, "input_is_01b");
	sc_trace(tf, mon_e, "input_is_10b");
	sc_trace(tf, mon_f, "input_is_11b");

	//start simulation, duration 20 systemC nanoseconds
	sc_start(40, SC_NS);
	return 0;
}
