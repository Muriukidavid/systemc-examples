#include <systemc.h>


SC_MODULE (NANDGATE){
	sc_in <bool> a, b;
	sc_out <bool> c;


void NANDGATE_method();
~NANDGATE();

SC_CTOR (NANDGATE){
	SC_METHOD (NANDGATE_method);
	sensitive <<a<<b;

    
};

};
