/*
 * decoder_2by4.cc
 *
 *  Created on: May 27, 2018
 *      Author: Bmaake
 */

#ifndef MONITOR_H_
#define MONITOR_H_
#include<iostream>
#include<systemc>

using namespace std;

SC_MODULE(monitor){
sc_in<bool> m_a, m_b, m_c, m_d, m_e, m_f;

SC_CTOR(monitor){
	SC_METHOD(monita);
	sensitive<<m_a<<m_b<<m_c<<m_d<<m_e<<m_f;
	dont_initialize();
}

void monita(void){
cout<<"at "<<sc_time_stamp()<<" input is: "<<m_f<<" & "<<m_e<<" outputs are: "<<m_a <<"   "<<m_b <<"   "<<m_c <<"   "<<m_d <<endl;
}
};
#endif /* MONITOR_H_ */
