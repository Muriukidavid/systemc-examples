/*
 * monitor.h
 *
 *  Created on: May 22, 2018
 *      Author: ruthie
 */
#ifndef MONITOR_H_
#define MONITOR_H_
#include<iostream>
#include<systemc.h>

using namespace std;

SC_MODULE(monitor){
sc_in<bool> m_a, m_b, m_c, m_d, m_e, m_f;

SC_CTOR(monitor){
	SC_METHOD(monita);
	sensitive<<m_c<<m_d<<m_e<<m_f;
	dont_initialize();//ensures you don't prematurely report the values before sc_start is called
}

void monita(void){
cout<<"at "<<sc_time_stamp()<<" input is: "<<m_a<<" "<<m_b<<" outputs are: "<<m_c<<" "<<m_d<<" "<<m_e<<"  "<<m_f<<endl;
}
};
#endif /* MONITOR_H_ */





