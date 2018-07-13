#include<systemc.h>

SC_MODULE(monitor){
	sc_in<bool> m_din, m_dout,m_do1,m_do2,m_do3;
	
	void mon(void);
	
	SC_CTOR(monitor){
		SC_METHOD(mon);
		sensitive<<m_din<<m_dout;
		dont_initialize();
	}
};
