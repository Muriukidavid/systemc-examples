#include "nandgate.h"

void nandgate:: nandgate_method (void){
	z_nand = (!(x_nand&&y_nand));
}

nandgate:: ~nandgate(){
	//delete gt1;
}
