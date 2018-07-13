#include "ALU.h"

void ALU::operate()
{
    {
        ZERO = false;
        data1 = OP1.read();
        data2 = OP2.read();
        
        switch(OPCODE.read())
        {
                
            case 0:
                result = data1 + data2;
                break;
                
            case 1:
                result = data1 - data2;
                break;
                
            case 2:
                result = data1 + 1;
                break;
                
            case 3:
                result = data1 - 1;
                break;
                
            case 4:
                result = data1 & data2;
                break;
                
            case 5:
                result = data1 | data2;
                break;
                
            case 6:
                result.range(3, 0) = ~(data1 & data2);
                break;
                
            case 7:
                result = data1 ^ data2;
                break;
                
        }

		RESULT.write(result.range(3, 0));
        
        CARRY.write((bool) result[4]);
        
        if(result == 0)
            ZERO.write(true);
    }
}
