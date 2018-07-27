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
sc_in<bool> m_e, m_f,m_d,m_c;

SC_CTOR(monitor){
	SC_METHOD(monita);
	sensitive<<m_c<<m_d;
	dont_initialize();
}

void monita(void){
cout<<"at "<<sc_time_stamp()<<" input is: "<<m_c<<" outputs are: "<<m_d<<" and "<<m_e<<endl;
}
};
#endif /* MONITOR_H_ */
