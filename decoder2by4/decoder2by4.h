#include<systemc.h>
#include "../decoder1by2/decoder_1by2.h"
#include "andgate.h"
SC_MODULE(decoder2by4){
	//ports
	sc_in<bool> d_in1, d_in2;
	sc_out<bool> d_out1, d_out2, d_out3, d_out4;
	//signals
	sc_signal<bool> sig3,sig4,sig5,sig6;
	//instances of modules
	decoder1by2 *dec1, *dec2;
	andgate *andgt1, *andgt2, *andgt3, *andgt4;
	//constructor
	SC_CTOR(decoder2by4){
		//initialize instances of modules
		dec1 = new decoder1by2("dec1");
		dec2 = new decoder1by2("dec2");
		andgt1 = new andgate("andgt1");
		andgt2 = new andgate("andgt2");
		andgt3 = new andgate("andgt3");
		andgt4 = new andgate("andgt4");
		//interconnect the module instances with signals
		//inputs
		dec1->a(d_in1);
		dec2->a(d_in2);
		//sig3
		dec1->b(sig3);
		andgt1->in1(sig3);
		andgt2->in1(sig3);
		//sig4
		dec1->c(sig4);
		andgt3->in1(sig4);
		andgt4->in1(sig4);
		//sig5	
		dec2->b(sig5);
		andgt1->in2(sig5);
		andgt3->in2(sig5);
		//sig6	
		dec2->c(sig6);
		andgt2->in2(sig6);
		andgt4->in2(sig6);
		//Outputs
		andgt1->out(d_out1);
		andgt2->out(d_out2);
		andgt3->out(d_out3);
		andgt4->out(d_out4);
	}

	~decoder2by4(){
		delete dec1;
		delete dec2;
		delete andgt1;
		delete andgt2;
		delete andgt3;
		delete andgt4;
	}
};
