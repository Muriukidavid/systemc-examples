#include <systemc.h>

SC_MODULE(alu){
	
	sc_in < sc_uint<4> > op;
	sc_in < sc_uint<8> > opA,opB;
	sc_out < bool > zero;
	sc_out < sc_uint<8> >result;

	sc_uint<8> dataA, dataB, res;

	void operate(){
		zero = false;
		dataA = opA.read();
		dataB = opB.read();
		
		switch(op.read()){
			
			case 0:
				res = dataA && dataB;
				break;

			case 1:
				res = dataA || dataB;
				break;

			case 2:
				res = dataA + dataB;
				break;
                
            case 3:
				res = dataA ^ dataB;
				break;
            
            case 4:
				res = ++dataA;
				break;
                
            case 5:
				res = --dataA;
				break;

			case 6:
				res = dataA - dataB;
				break;
			
			case 12:
				res = ~(dataA && dataB);
				break;
			
		}
		result.write(res);
		if(res == 0)
			zero = true;
	}

	
	
	SC_CTOR(alu){
		SC_METHOD(operate);
			sensitive << opA << opB << op;
	}

};
