#include "monitor.h"
#include<iostream>

using namespace std;

//SC_MODULE(monitor){
//sc_in<bool> m_dout, m2_dout;
//
//SC_CTOR(monitor){
//	SC_METHOD(monita);
//	sensitive<<m_dout<<m2_dout;
//	dont_initialize();
//}

void monitor::mon(void){
	cout<<"at "<<sc_timestamp()<<" input is: "m_din<<" output is: "<<m2_din<<endl;
}
