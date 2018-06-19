#include "dff.h"

void dff:: dff_method (void){
	
	dout1 = (din1==1)?0:1;
	dout2 = (din2==1)?0:1;
	dout3 = (din7==0)?1:0;
	dout4 = (din4==1 && din3==1)?1:0;
	dout5 = (din5==1 && din6==1)?0:1; 
}

dff:: ~dff(){
	//delete gt1;
}
