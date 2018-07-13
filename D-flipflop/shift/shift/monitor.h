#include<systemc.h>

SC_MODULE(monitor){
	sc_in<bool> m_din, m_QD,m_QA,m_QB,m_QC;
	
	void mon(void);
	
	SC_CTOR(monitor){
		SC_METHOD(mon);
		sensitive<<m_din<<m_QD<<m_QA<<m_QB<<m_QC;
		dont_initialize();
	}
};
