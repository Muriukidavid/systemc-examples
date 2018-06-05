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
sc_in<bool> m_a, m_b,m_c;

SC_CTOR(monitor){
	SC_METHOD(monita);
	sensitive<<m_b<<m_c;
	dont_initialize();
}

void monita(void){
cout<<"at "<<sc_time_stamp()<<" input is: "<<m_a<<" outputs are: "<<m_b<<" and "<<m_c<<endl;
}
};
#endif /* MONITOR_H_ */
