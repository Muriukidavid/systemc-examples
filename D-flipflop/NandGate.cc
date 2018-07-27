/*
 * NandGate.c
 *
 *  Created on: Jun 26, 2018
 *      Author: njoro
 */
#include "NandGate.h"
void Nand_gate:: add_invert method (void){
	//sc_signal<bool> iNand_in1,iNand_in2,Nout;
	Nand_out=(Nand_in1==0 && Nand_in2==0)?1:0;
	Nand_out=(Nand_in1==0 && Nand_in2==1)?1:0;
	Nand_out=(Nand_in1==1 && Nand_in2==0)?1:0;
	Nand_out=(Nand_in1==0 && Nand_in2==1)?1:0;

Nand_Gate:: ~Nand_gate(){
		//delete gt1
}


