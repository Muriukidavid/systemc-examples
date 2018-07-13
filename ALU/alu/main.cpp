#include <iostream>
#include <systemc.h>
#include "operations.h"
#include "monitor.h"
#include "driver.h"

int sc_main(int argc, char* argv[]){

	sc_core::sc_report_handler::set_actions( "/IEEE_Std_1666/deprecated",sc_core::SC_DO_NOTHING );

	sc_signal < sc_uint<4> > num1,num2,ans;
	sc_signal < sc_uint<4> > code;  
	sc_signal <bool> zero_val;
	sc_clock TestClk("Clock", 5, SC_NS,1,SC_NS); 

	driver dr("driver");   
	dr.operand1(num1);   
	dr.operand2(num2);
	dr.opcode(code);
	dr.clk(TestClk);

	operation exec("operation");
	exec.operand1(num1);
	exec.operand2(num2);
	exec.opcode(code);
	exec.result(ans);
	exec.zero(zero_val);
	
	monitor mon("monitor");
	mon.operand1(num1);   
	mon.operand2(num2);   
	mon.opcode(code);
	mon.result(ans);
	mon.clk(TestClk);   
	mon.zero(zero_val); 

	sc_start();

	return 0;
}


