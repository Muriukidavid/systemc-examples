#include "driver.h"

void driver::drive(void){
	z=x=y=0;
	
	for(int a=0; a<8; a++){
		y++;
		x=8-y;
		d_OPCODE.write(z); // 0,1,2,3,4,5,6,7
		d_OP1.write(x);
		d_OP2.write(y);
		z++;
		wait(5,SC_NS);
	}
}
