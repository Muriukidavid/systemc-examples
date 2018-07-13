#include "shiftreg.h"


void shiftreg:: shiftreg_method (void){
		if(clr){
	QD = 0;
	}else
	{
	QD = DFFD.dout;
}
	}



