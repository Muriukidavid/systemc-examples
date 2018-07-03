#include "nand_gate.h"

nand_gate::~nand_gate() {
//delete stuff :P
}

void nand_gate::gate(void) {
	c = !(a && b);
}
