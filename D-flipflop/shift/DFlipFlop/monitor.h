#include<systemc.h>

SC_MODULE(monitor){
	sc_in<bool> m_din, m_dout ,m_clr;
	
	void mon(void);
	
	SC_CTOR(monitor){
		SC_METHOD(mon);
		sensitive<<m_din<<m_dout <<m_clr;
		dont_initialize();
	}
};
