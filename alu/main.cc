#include "systemc.h"
#include "driver.h"
#include "alu.h"
#include "monitor.h"

int sc_main(int argc, char* argv[]) {

	sc_signal <sc_uint<4> > A,B,C;
	sc_signal <sc_uint<3> > OP;
	sc_signal <bool> zero, carry;

	sc_clock clk("Clock", 10, SC_NS,1,SC_NS);

	driver dr("Driver_1");
	dr.opA(A);
	dr.opB(B);
	dr.op(OP);
	dr.clk(clk);


	alu alu("ALU");
	alu.opA(A);
	alu.opB(B);
	alu.op(OP);
	alu.result(C);
	alu.zero(zero);
	alu.carry(carry);

	monitor mon1("Monitor");
	mon1.opA(A);
	mon1.opB(B);
	mon1.op(OP);
	mon1.result(C);
	mon1.clk(clk);
	mon1.zero(zero);
	mon1.carry(carry);

	sc_trace_file *fp;
	fp=sc_create_vcd_trace_file("vcd_trace");
	fp->set_time_unit(1, SC_NS);

	sc_trace(fp, clk, "Clk");
	sc_trace(fp, A, "Operand_1");
	sc_trace(fp, B, "Operand_2");
	sc_trace(fp, OP, "Operand_code");
	sc_trace(fp, C, "Result");
	sc_trace(fp, carry, "Carry/Borrow");
	sc_trace(fp, zero, "Zero");

	sc_start();
sc_close_vcd_trace_file(fp);


	return 0;
}

