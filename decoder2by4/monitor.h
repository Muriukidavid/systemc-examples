#ifndef MONITOR_H_
#define MONITOR_H_
#include<iostream>
#include<systemc>

using namespace std;

SC_MODULE(monitor){

	sc_in<bool> m_A0;
	sc_in<bool> m_A1;
	sc_in<bool> m_D0;
	sc_in<bool> m_D1;
	sc_in<bool> m_D2;
	sc_in<bool> m_D3;
						

	SC_CTOR(monitor){
		SC_METHOD(monita);
		sensitive<<m_D0<<m_D1<<m_D2<<m_D3;
		dont_initialize();
	}

	void monita(void){
		cout<<"at "<<sc_time_stamp()<<"input A1: "<<m_A1<<"input A0: "<<m_A0<<"outputs are: "<<m_D3<<" "<<m_D2<<" "<<m_D1<<" 			"<<m_D0<<endl;
	}
};
#endif /* MONITOR_H_ */
