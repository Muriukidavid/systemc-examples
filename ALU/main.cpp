#include<systemc.h>
#include "driver.h"
#include "ALU.h"
#include "monitor.h"

int sc_main(int argc, char* argv[]){
	 sc_core::sc_report_handler::set_actions( "/IEEE_Std_1666/deprecated",
                                           sc_core::SC_DO_NOTHING );

	sc_signal < sc_uint<4> >a, b, r;
	sc_signal < sc_uint<3> >op;	
	sc_signal<bool> carry, zero;
	sc_clock clock("clk", 10, SC_NS, 1, SC_NS);

	driver driver1("Driver");
	driver1.opA(a);
	driver1.opB(b);
	driver1.op(op);
	driver1.clk(clock);

	ALU alu("ALU");
	alu.OP1(a);
	alu.OP2(b);
	alu.OPCODE(op);
	alu.RESULT(r);
	alu.ZERO(zero);
	alu.CARRY(carry);

	mon monitor1("Monitor");
	monitor1.opA(a);
	monitor1.opB(b);
	monitor1.op(op);
	monitor1.result(r);
	monitor1.clk(clock);
	monitor1.zero(zero);
	monitor1.carry(carry);
	
	sc_trace_file *fp;
	fp=sc_create_vcd_trace_file("vcd_trace");
	fp->set_time_unit(1, SC_NS);

	sc_trace(fp, clock, "Clk");
	sc_trace(fp, a, "Operand_1");
	sc_trace(fp, b, "Operand_2");
	sc_trace(fp, op, "Opcode");
	sc_trace(fp, r, "Result");
	sc_trace(fp, carry, "Carry/Borrow");
	sc_trace(fp, zero, "Zero");

	sc_start();
	sc_close_vcd_trace_file(fp);
	return 0;
}
