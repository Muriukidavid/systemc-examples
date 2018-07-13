#include "driver.h"

void driver::drive(void){
	while(1){
		d_in = 1;
		wait(5,SC_NS);
		d_in = 0;
		wait(5,SC_NS);
	}
}
