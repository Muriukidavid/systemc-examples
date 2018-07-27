#include<systemc.h>

SC_MODULE(monitor){
	sc_in<bool> m_din, m2_din;
	
	void mon(void);
	
	SC_CTOR(monitor){
		SC_METHOD(mon);
		sensitive<<m_din<<m2_din;
		dont_initialize();
	}
};
