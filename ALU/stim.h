#include "systemc.h" 
SC_MODULE(stim) {
	sc_out < sc_uint<8> > opA,opB;
	sc_out < sc_uint<4> > op;
	sc_in<bool> Clk;

	void StimGen()   {

		opA.write(0b111);     
		opB.write(0b001);
		op.write(0);

		wait(10,SC_NS);

		opA.write(0b111);     
		opB.write(0b001);
		op.write(1);

		wait(10,SC_NS);

		opA.write(0b111);     
		opB.write(0b001);
		op.write(2);

		wait(10,SC_NS);
        
        
        opA.write(0b111);     
		opB.write(0b001);
		op.write(3);

		wait(10,SC_NS);

		opA.write(0b111);     
		opB.write(0b001);
		op.write(4);

		wait(10,SC_NS);

		opA.write(0b111);     
		opB.write(0b001);
		op.write(5);

		wait(10,SC_NS);

		opA.write(111);     
		opB.write(001);
		op.write(6);

		wait(10,SC_NS);
        
        opA.write(0b111);     
		opB.write(0b001);
		op.write(12);

		wait(10,SC_NS);


		sc_stop();   
	}   

	SC_CTOR(stim)   {
		SC_THREAD(StimGen);
	} 
};
