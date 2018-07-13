#include "operations.h"

void operation::operate(){

	op1 = operand1.read();
	op2 = operand2.read();
	op = opcode.read();

	switch(op){
		case 0:	// add
			res = op1 + op2;
			break;

		case 1:	// subtract
			res = op1 - op2;
			break;

		case 2:	// increment
			res = op1++;
			break;

		case 3:	// decrement
			res = op1--;
			break;

		case 4:	// and
			res = op1 && op2;
			break;

		case 5:	// nand
			res = ~(op1 && op2);
			break;

		case 6:	// or
			res = op1 || op2;
			break;	

		case 7:	// xor
			res = op1 ^ op2;	
			break;	
	}

	zero = (res==0)?true:false;
	result.write(res);
}

