#include "dff.h"

void dff:: dff_method (void){

	dout1 = (din1==1)?0:1;
	dout2 = (din2==1)?0:1;
	dout3 = (din7==0)?1:0;
	dout4 = (din4==1 && din3==1)?1:0;
	dout5 = (din5==1 && din6==1)?0:1; 

	dout6 = (din8==1 && din9==1)?0:1;
	dout7 = (din10==0 && din11==1)?1:0;
	dout8 = (din12==1 && din13==0)?1:0;
	dout9 = (din9==1)?0:1;
}

dff:: ~dff(){
	//delete gt1;
}
