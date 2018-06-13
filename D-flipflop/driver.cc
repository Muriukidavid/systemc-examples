#include "driver.h"

void driver::drive(void){
	while(1){
		d_din = 1;
		wait(1,SC_PS);
		d_din = 0;
		wait(2,SC_PS);
		d_din = 1;
		wait(1,SC_PS);
		d_din = 0;
		wait(1,SC_PS);
		d_din = 1;
		wait(3,SC_PS);
		d_din = 0;
		wait(1,SC_PS);
	}
}
