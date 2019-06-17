#ifndef NANDGATE_H_
#define NANDGATE_H_
#include "systemc.h"
SC_MODULE(nand)          // declare nand2 sc_module
{
  sc_in<bool> A, B;       // input signal ports
  sc_out<bool> F;         // output signal ports

  void gate(void);        // a C++ function
	

  SC_CTOR(nand)          // constructor for nand
  {
    SC_METHOD(gate);  // register nand with kernel
    sensitive << A << B;  // sensitivity list
  }
};
#endif /* NANDGATE_H_ */
