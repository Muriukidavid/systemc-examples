#include<systemc.h>

SC_MODULE(monitor){
	sc_in<bool> m_din, m_QA,m_QB,m_QC,m_QD;
	
	void mon(void);
	
	SC_CTOR(monitor){
		SC_METHOD(mon);
		sensitive<<m_din<<m_QA<<m_QB<<m_QC<<m_QD;
		dont_initialize();
	}
};
