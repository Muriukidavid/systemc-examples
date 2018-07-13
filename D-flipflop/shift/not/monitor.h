#include<systemc.h>

SC_MODULE(monitor){
	sc_in<bool> m_in, m_out;
	
	void mon(void);
	
	SC_CTOR(monitor){
		SC_METHOD(mon);
		sensitive<<m_in<<m_out;
		dont_initialize();
	}
};
