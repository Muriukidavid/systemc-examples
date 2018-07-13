#include "nand.h"

void nand::gate(void)
  {
    F=( !(A && B) );
  }
  
