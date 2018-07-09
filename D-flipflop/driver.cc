#include "driver.h"

void driver::drive(void){
	d_din1 = 1;
	d_din2 = 1;
	while(1){
		d_din = 1;
		wait(5,SC_NS);
		d_din = 0;
		wait(5,SC_NS);
	}
}
