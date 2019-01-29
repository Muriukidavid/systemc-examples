#include "driver.h"

void driver::drive(void){
	d_clr = 0;
	//wait(6,SC_NS);
	while(1){
		d_din = 1;
		wait(40,SC_NS);
		d_din = 0;
		wait(40,SC_NS);
	}
}
