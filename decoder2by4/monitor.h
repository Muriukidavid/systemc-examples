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
sc_in<bool> m_a, m_b, m_w, m_x, m_y, m_z;

SC_CTOR(monitor){
		SC_METHOD(monita);
		sensitive<<m_w<<m_x<<m_y<<m_z;
		dont_initialize();
}

void monita(void){
cout<<"at "<<sc_time_stamp()<<" inputs are: "<<m_a<<" and "<<m_b<<" outputs are: "<<m_w<<" , "<<m_x<<" , "<<m_y<<" and "<<m_z<<endl;
}
};
#endif /* MONITOR_H_ */
