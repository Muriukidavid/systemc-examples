#include <systemc.h>
#include "dff.h"


SC_MODULE (regista) {
	sc_in <bool> clock1;
	sc_in <bool> d_in;
	sc_out <bool> d_out;
        sc_signal<bool>do1,do2,do3,s_dout;
     
           
        dff d_ff;
        dff dff1;
        dff dff2;
        dff dff3;
        dff dff4;

	void regista_method(void);
	~regista();

	SC_CTOR (regista):dff1("d_ff1")
                     ,dff2("d_ff2")
                     ,dff3("d_ff3")
                     ,dff4("d_ff4");
{

                dff1.dout(do1);
                dff2.dout(do2);
                dff3.dout(do3);
                dff4.dout(s_dout);


                d_in(din);
                d_out(dout);
                clock1(clk);

               
            SC_METHOD (regista_method);   
			sensitive << clk.pos();

}	
};
