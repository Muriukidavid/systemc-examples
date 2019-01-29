#include<systemc.h>

SC_MODULE(monitor){
	sc_in<bool>  m_dout, m_clr, m_din;
	
	void monita(void);
	
	SC_CTOR(monitor){
		SC_METHOD(monita);
		sensitive<<m_din<<m_clr<<m_dout;
		dont_initialize();
	}
};
