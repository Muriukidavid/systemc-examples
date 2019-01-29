#include<systemc.h>

SC_MODULE(monitor){
	sc_in<bool> m_din, m_s_out;
	
	void monita(void);
	
	SC_CTOR(monitor){
		SC_METHOD(monita);
		sensitive<<m_s_out;
		dont_initialize();
	}
};
