#include "systemc.h"
#include "dff.h"
#include "NOT.h"

SC_MODULE (shiftR){
    
    //the inputs, outputs and signals of the shift register
    sc_in <bool> clk;
    sc_in <bool> sr_in;
    sc_in <bool> CLR;
    sc_signal <bool> QA, QB, QC, QD;
    //declare dff objects as variables
        dff ffA;
        dff ffB;
        dff ffC;
        dff ffD;
    
        
    void shiftR_method (void);
        
    SC_CTOR (shiftR): ffA("flipflop Instance1"),
                      ffB("flipflop Instance2"),
                      ffC("flipflop Instance3"),
                      ffD("flipflop Instance4")
                      
                      {
                          //Connections made within the shift register
                        ffA.din(sr_in);
                        ffA.dout(QA);
                        ffB.din(QA);
                        ffB.dout(QB);
                        ffC.din(QB);
                        ffC.dout(QC);
                        ffD.din(QC);
                        ffD.dout(QD);
                          
            SC_METHOD (shiftR_method);
			sensitive << clk.pos();
                          
        };
};
