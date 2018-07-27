#include "driver.h"

void driver::drive(void){
	while(1){
		s_din = 1;
		wait(5,SC_NS);
		s_din = 0;
		wait(5,SC_NS);
	}
}
