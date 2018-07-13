#include "alu.h"

void alu::calculate() {
	zero = false;

	switch (op.read()) {
		case 0:
			temp_result = opA.read() + opB.read();
			break;

		case 1:
			temp_result = opA.read() - opB.read();
			break;

		case 2:
			temp_result = opA.read() + 1;
			break;

		case 3:
			temp_result = opA.read() - 1;
			break;

		case 4:
			temp_result = opA.read() & opB.read();
			break;

		case 5:
			temp_result = opA.read() | opB.read();
			break;

		case 6:
			temp_result.range(3, 0) = ~(opA.read() & opB.read());
			break;

		case 7:
			temp_result = opA.read() ^ opB.read();
			break;

	}

	result.write(temp_result.range(3, 0));

	carry.write((bool) temp_result[4]);

	if (temp_result == 0)
		zero.write(true);
}
