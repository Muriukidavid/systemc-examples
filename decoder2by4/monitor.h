#ifndef MONITOR_H_
#define MONITOR_H_
#include<iostream>
#include<systemc>

using namespace std;

SC_MODULE(monitor){

	sc_in<bool> m_a1;
	sc_in<bool> m_a2;
	sc_in<bool> m_3;
	sc_in<bool> m_4;
	sc_in<bool> m_5;
	sc_in<bool> m_6;
						

	SC_CTOR(monitor){
		SC_METHOD(monita);
		sensitive<<m_3<<m_4<<m_5<<m_6;
		dont_initialize();
	}

	void monita(void){
		cout<<"at "<<sc_time_stamp()<<"input A: "<<m_a2<<"input B: "<<m_a1<<"outputs are: "<<m_3<<" "<<m_4<<" "<<m_5<<" 	"<<m_6<<endl;
	}
};
#endif /* MONITOR_H_ */
