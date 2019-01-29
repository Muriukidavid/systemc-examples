#include<systemc.h>

SC_MODULE(monitor){
	sc_in < sc_uint<3> > m_OPCODE;
	sc_in < sc_uint<4> > m_OP1, m_OP2;
	sc_in < bool > m_CARRY, m_ZERO;
	sc_in < sc_uint<4> > m_RESULT;
	
	void monita(void);
	
	SC_CTOR(monitor){
		SC_METHOD(monita);
		sensitive<<m_OPCODE<<m_RESULT;
		dont_initialize();
	}
};
