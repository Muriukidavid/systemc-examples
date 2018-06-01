/*
 * monitor.h
 *
 *  Created on: Mar 4, 2016
 *      Author: karibe
 */

#ifndef MONITOR_H_
#define MONITOR_H_
#include<iostream>
#include<systemc>

using namespace std;

SC_MODULE(monitor){
sc_in<bool> m_m, m_n, m_q, m_r, m_s, m_t;

SC_CTOR(monitor){
	SC_METHOD(monita);
	sensitive<<m_q<<m_r<<m_s<<m_t;
	dont_initialize();
}

void monita(void){
cout<<"at "<<sc_time_stamp()<<" input is: "<<m_m<<" and "<<m_n<<" outputs are: "<<m_q<<"  "<<m_r<<"  "<<m_s<<"  "<<m_t<<endl;
}
};
#endif /* MONITOR_H_ */
