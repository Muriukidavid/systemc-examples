#include<systemc.h>

SC_MODULE(monitor){
	sc_in<bool> m_A,m_B, m_F;
	
	void mon(void);
	
	SC_CTOR(monitor){
		SC_METHOD(mon);
		sensitive<<m_A<<m_B<<m_F;
		dont_initialize();
	}
};
