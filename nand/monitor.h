#include<systemc.h>

SC_MODULE(monitor){
	sc_in<bool> m_A, m_B, m_out;
	
	void monita(void);
	
	SC_CTOR(monitor){
		SC_METHOD(monita);
		sensitive<<m_A<<m_B<<m_out;
		dont_initialize();
	}
};
