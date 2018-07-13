#include "driver.h"

void driver::drive(void){
	while(1){
		d_A = 1;
		wait(5,SC_NS);
		d_A = 0;
		wait(5,SC_NS);
		d_B= 1;
		wait(5,SC_NS);
		d_B= 0;
		wait(5,SC_NS);
	}
}
