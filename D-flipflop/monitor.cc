#include "monitor.h"
#include<iostream>

using namespace std;

void monitor::mon(void){
	cout<<"at "<<sc_time_stamp()<<" input is: "<<m_din<<" output is: "<<m_1<< "  " <<m_2<< "  " <<m_3<< "  " <<m_dout<<endl;
}

