#include "driver.h"

void driver::drive()   {
	
		opA.write(0b1111);     
		opB.write(0b001);
		op.write(0);

		wait(10,SC_NS);

		opA.write(0b001);     
		opB.write(0b1111);
		op.write(1);

		wait(10,SC_NS);

		opA.write(0b101);     
		opB.write(0b011);
		op.write(2);

		wait(10,SC_NS);

		opA.write(0b101);     
		opB.write(0b011);
		op.write(3);

		wait(10,SC_NS);

		opA.write(0b101);     
		opB.write(0b011);
		op.write(4);

		wait(10,SC_NS);

		opA.write(0b101);     
		opB.write(0b011);
		op.write(5);

		wait(10,SC_NS);

		opA.write(0b101);     
		opB.write(0b011);
		op.write(6);

		wait(10,SC_NS);

		opA.write(0b101);     
		opB.write(0b011);
		op.write(7);	
			
		wait(10,SC_NS);
		
		sc_stop();   
	}   
