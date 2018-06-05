#ifndef DECODER_2BY4_H_
#define DECODER_2BY4_H_
#include<systemc.h>
#include "andgate.h"
#include "decoder_1by2.h"

   

SC_MODULE(decoder_2by4){
	//input and output ports

	sc_in<bool> d_in1,d_in2;
	sc_out<bool> d_out1,d_out2,d_out3,d_out4;


	decoder *dec1, *dec2;
	and_gate *andgt1 ,*andgt2, *andgt3, *andgt4;

	//some signals for interconnections
	sc_signal<bool> sig3,sig4,sig5,sig6;

	SC_CTOR(decoder_2by4){
		andgt1=new and_gate ("andgate_1");
		andgt2=new and_gate ("andgate_2");
		andgt3=new and_gate ("andgate_3");
		andgt4=new and_gate ("andgate_4");

		dec1= new decoder ("dec1");
		dec2= new decoder ("dec2");

		//input
		dec1->in(d_in1);
		dec2->in(d_in2);
		
		//sig3
		dec1->out1(sig3);
		andgt1->A(sig3);
		andgt2->A(sig3);

		//sig4
		dec1->out2(sig4);
		andgt3->A(sig4);
		andgt4->A(sig4);

		//sig5
		dec2->out1(sig5);
		andgt1->B(sig5);
		andgt3->B(sig5);

		//sig6
		dec2->out2(sig6);
		andgt2->B(sig6);
		andgt4->B(sig6);

		//output
		andgt1->F(d_out1);
		andgt2->F(d_out2);
		andgt3->F(d_out3);
		andgt4->F(d_out4);
	}

	~decoder_2by4(){
		delete dec1;
		delete dec2;
		delete andgt1;
		delete andgt2;
		delete andgt3;
		delete andgt4;
	}
};



#endif /* DECODER_2BY4_H_ */

