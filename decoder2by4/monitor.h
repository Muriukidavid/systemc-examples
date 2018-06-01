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
sc_in<bool> m_a, m_b,m_c,m_d,m_e,m_f;

SC_CTOR(monitor){
	SC_METHOD(monita);
	sensitive<<m_b<<m_c<<m_e<<m_f;
	dont_initialize();
}

void monita(void){
cout<<"At "<<sc_time_stamp()<<" inputs are: "<<m_a<<" and "<<m_d<<" outputs are: "<<m_b<<" and "<<m_c<<" and "<<m_e<<" and "<<m_f<<endl;
}
};
#endif /* MONITOR_H_ */
