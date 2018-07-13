#ifndef NANDGATE_H_
#define NANDGATE_H_
#include "systemc.h"
SC_MODULE(nand2)          // declare nand2 sc_module
{
  sc_in<bool> A, B;       // input signal ports
  sc_out<bool> F;         // output signal ports

  void gate(void);        // a C++ function
	

  SC_CTOR(nand2)          // constructor for nand2
  {
    SC_METHOD(gate);  // register nand2 with kernel
    sensitive << A << B;  // sensitivity list
  }
};
#endif /* NANDGATE_H_ */