#include <systemc.h>


SC_MODULE (nandgate){
    sc_in <bool> x_nand, y_nand;
    sc_out <bool> z_nand;    

    void nandgate_method(void);
    ~nandgate();

    SC_CTOR (nandgate) {
        SC_METHOD (nandgate_method);
            sensitive << x_nand << y_nand;
    }
};
