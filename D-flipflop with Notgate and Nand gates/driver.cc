#include "driver.h"

void driver::drive(void){
	while(1){
		d_din = 1;
		wait(10,SC_NS);
		d_din = 0;
		wait(5,SC_NS);
        
	}
	
}
