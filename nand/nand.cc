#include "nand.h"

void nand_gate::n_gate(void)
  {
  	next_trigger();
    out=( !(A && B) );
  }
  
