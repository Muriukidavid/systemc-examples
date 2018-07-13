

#ifndef MONITOR_H_
#define MONITOR_H_
#include<iostream>
#include<systemc>

using namespace std;

SC_MODULE(monitor){
sc_in<bool> m_a, m_b, m_e, m_f, m_g, m_h;

SC_CTOR(monitor){
	SC_METHOD(monita);
	sensitive<<m_e<<m_f<<m_g<<m_h;
	dont_initialize();
}

void monita(void){
cout<<"at "<<sc_time_stamp()<<" input is: "<<m_a<<" , "<<m_b<<" outputs are: "<<m_h<<" , "<<m_g<<" , "<<m_f<<" , " <<m_e<<endl;
}
};
#endif /* MONITOR_H_ */
