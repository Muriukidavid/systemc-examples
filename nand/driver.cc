#include "driver.h"

void driver::drive(void){
	while(true){
		d_A = 0;
		d_B = 0;
		wait(5,SC_NS);
		d_A = 0;
		d_B = 1;
		wait(5,SC_NS);
		d_A = 1;
		d_B = 0;
		wait(5,SC_NS);
		d_A = 1;
		d_B = 1;
		wait(5,SC_NS);
	}
}
