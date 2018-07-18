#include "nandgate.h"

void nandgate:: nandgate_method (void){
	out3 = (!(in1 && in2));
}

nandgate:: ~nandgate(){
	//delete gate;
}
