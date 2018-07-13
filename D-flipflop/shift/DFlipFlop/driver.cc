#include "driver.h"

void driver::drive(void){
	d_clr =0;
	d_din = 0;
	wait(11,SC_NS);
	while(true){
		d_din = 1;
		wait(11,SC_NS);
		d_din = 0;
		wait(11,SC_NS);
	}
}
