#include "driver.h"

void driver::drive(){

	operand1.write(0b001);          
	operand2.write(0b001);
	opcode.write(0);

	wait(10,SC_NS);

	operand1.write(0b001);          
	operand2.write(0b001);
	opcode.write(1);

	wait(10,SC_NS);

	operand1.write(0b001);          
	operand2.write(0b001);
	opcode.write(2);

	wait(10,SC_NS);

	operand1.write(0b001);          
	operand2.write(0b001);
	opcode.write(3);

	wait(10,SC_NS);

	operand1.write(0b001);          
	operand2.write(0b001);
	opcode.write(4);

	wait(10,SC_NS);

	operand1.write(0b001);          
	operand2.write(0b001);
	opcode.write(5);

	wait(10,SC_NS);

	operand1.write(0b001);          
	operand2.write(0b001);
	opcode.write(6);

	wait(10,SC_NS);

	operand1.write(0b001);          
	operand2.write(0b001);
	opcode.write(7);

	sc_stop();
}
