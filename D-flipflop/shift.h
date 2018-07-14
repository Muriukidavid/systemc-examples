#include <systemc.h>
#include "dff.h"

SC_MODULE(shiftrg){
    sc_in<bool> in, clk;
    sc_out<bool> out1, out2, out3, out4;
    sc_signal<bool> sig1, sig2, sig3;

    dff dff1;
    dff dff2;
    dff dff3;
    dff dff4;

    SC_CTOR(shiftrg):dff1("dff1")
                    ,dff2("dff2")
                    ,dff3("dff3")
                    ,dff4("dff4"){
        

                    }

}: