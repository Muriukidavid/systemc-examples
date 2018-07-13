#include "shiftreg.h"


void shiftreg:: shiftreg_method (void){
	sDin=din;
}

shiftreg:: ~shiftreg(){
	    delete DFFA;
		delete DFFB;
		delete DFFC;
		delete DFFD;	
}