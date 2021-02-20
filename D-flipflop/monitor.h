#include<systemc.h>

SC_MODULE(monitor){
	sc_in<bool> m_din, m_dout, m_d1, m_d2, m_d3;
	
	void mon(void);
	
	SC_CTOR(monitor){
		SC_METHOD(mon);
		sensitive<<m_din<<m_dout<<m_d1<<m_d2<<m_d3;
		dont_initialize();
	}
};

