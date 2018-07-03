#include <systemc.h>


SC_MODULE (nandgate){
    sc_in <bool> x, y;
    sc_out <bool> z;    

    void nandgate_method(void);
    ~nandgate();

    SC_CTOR (nandgate) {
        SC_METHOD (nandgate_method);
            sensitive << x << y;
    }
};