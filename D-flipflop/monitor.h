#include<systemc.h>

SC_MODULE(monitor){
	sc_in<bool> m_din, m_dff1dff2, m_dff2dff3, m_dff3dff4, m_dout;
	
	void mon(void);
	
	SC_CTOR(monitor){
		SC_METHOD(mon);
		sensitive<<m_din<<m_dff1dff2<<m_dff2dff3<<m_dff3dff4<<m_dout;
		dont_initialize();
	}
};
