#include <systemc.h>
#include "notgate.h"
#include "nandgate.h"

SC_MODULE (dff) {
	sc_in <bool> clk;
	sc_in <bool> din;
	sc_out <bool> dout;
        sc_signal<bool>in1,in4,out1,out2,out3,out4;
     
           
        not_gate notgate;
        nand_gate nand1;
        nand_gate nand2;
        nand_gate nand3;
        nand_gate nand4;

	void dff_method(void);
	~dff();

	SC_CTOR (dff):notgate("not_gate_instance")
                     ,nand1("nand_gate_1")
                     ,nand2("nand_gate_2")
                     ,nand3("nand_gate_3")
                     ,nand4("nand_gate_4"){

                notgate.x(in1);
                notgate.y(in4);

                nand1.a(in1);
                nand1.b(clk);
                nand2.a(clk);
                nand2.b(in4);

                nand3.a(out1);
                nand3.b(out2);
                nand4.a(out3);
                nand4.b(out4);

                nand1.c(out1);
                nand2.c(out4);
                nand3.c(out3);
                nand4.c(out2);

            SC_METHOD (dff_method);   
			sensitive << clk.pos();

}	
};
