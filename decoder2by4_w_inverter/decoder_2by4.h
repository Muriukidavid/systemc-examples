/*
 * decoder_2by4.h
 *
 *  Created on: Mar 4, 2016
 *      Author: karibe
 */

#ifndef DECODER_2BY4_H_
#define DECODER_2BY4_H_
#include<systemc.h>
#include"andgate.h"
#include"decoder_1by2.h"
#include"driver.h"

SC_MODULE(decoder2by4){	
//input and output ports
sc_in<bool> m,n;
sc_out<bool> q,r,s,t;
sc_signal<bool> in_m,in_n,out1, out2,out3,out4,out_q, out_r,out_s,out_t;
decoder *dec1by2_one, *dec1by2_two;
andgate *gate_1, *gate_2, *gate_3, *gate_4;

//constructor: where the processes are bound to simulation kernel
SC_CTOR(decoder2by4){
	dec1by2_one = new decoder("decoder_1by2_1");
	dec1by2_two = new decoder("decoder_1by2_2");
	gate_1 = new andgate("gate_instance_1");
	gate_2 = new andgate("gate_instance_2");
	gate_3 = new andgate("gate_instance_3");
	gate_4 = new andgate("gate_instance_4");

	dec1by2_one->a(m);
	dec1by2_one->b(out1);
	dec1by2_one->c(out2);

	dec1by2_two->a(n);
	dec1by2_two->b(out3);
	dec1by2_two->c(out4);

	gate_1->x(out1);
	gate_1->y(out3);
	gate_1->z(q);

	gate_2->x(out1);
	gate_2->y(out4);
	gate_2->z(r);

	gate_3->x(out2);
	gate_3->y(out3);
	gate_3->z(s);

	gate_4->x(out2);
	gate_4->y(out4);
	gate_4->z(t);

	/*SC_METHOD(decode2by4detals);
	dont_initialize();
	SC_METHOD(decode2by4);/*/
	sensitive<<m;
	sensitive<<n;
}

~decoder2by4(){
//delete stuff :P
}

void decode2by4(void){
	q=(m==0&&n==0)?1:0;
	r=(m==0&&n==1)?1:0;
	s=(m==1&&n==0)?1:0;
	t=(m==1&&n==1)?1:0;
}
void decode2by4detals(void){
}
};




#endif /* DECODER_2BY4_H_ */
