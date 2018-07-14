#include<systemc.h>
#include "driver.h"

void driver::drive(void) {

	opA.write(0b111);
	opB.write(0b001);
	op.write(0);

	wait(10, SC_NS);

	opA.write(0b111);
	opB.write(0b001);
	op.write(1);

	wait(10, SC_NS);

	opA.write(0b111);
	opB.write(0b001);
	op.write(2);

	wait(10, SC_NS);

	opA.write(0b111);
	opB.write(0b001);
	op.write(6);

	wait(10, SC_NS);

	opA.write(0b111);
	opB.write(0b001);
	op.write(7);

	wait(10, SC_NS);

	opA.write(111);
	opB.write(001);
	op.write(12);

	wait(10, SC_NS);

	sc_stop();
}
