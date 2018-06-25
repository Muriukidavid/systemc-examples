#include <systemc.h>

SC_MODULE (nandgate){
    sc_in <bool> in1, in2;
    sc_out <bool> out3;    

    void nandgate_method(void);
    ~nandgate();

    SC_CTOR (nandgate) {
        SC_METHOD (nandgate_method);
            sensitive << in1 << in2;
    }
};
