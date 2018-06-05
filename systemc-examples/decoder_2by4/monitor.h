/*
 * monitor.h
 *
 *  Created on: May 21, 2018
 *      Author: shaniz
 */
#ifndef MONITOR_H_
#define MONITOR_H_

#include<iostream>
#include<systemc.h>

//using namespace std;

//declaration of monitor
SC_MODULE(monitor){
//input
sc_in<bool> m_a, m_b, m_c, m_d, m_e, m_f;
//constructor
SC_CTOR(monitor){
	SC_METHOD(monita);
	sensitive<<m_c<<m_d<<m_e<<m_f;
	dont_initialize();
}

void monita(void){
cout<<"at "<<sc_time_stamp()<<" input are: "<<m_a<<" and "<<m_b<<" outputs are: "<<m_c<<" and "<<m_d<<" and "<<m_e<<" and "<<m_f<<endl;
}
};

#endif /* MONITOR_H_ */



