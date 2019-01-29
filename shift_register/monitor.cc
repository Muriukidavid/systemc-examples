#include "monitor.h"
#include<iostream>

using namespace std;

void monitor::mon(void){
	cout<<"at "<<sc_time_stamp()<<" clear is:"<<m_clr<<" input is: "<<m_din<<" output is: | "<<m_QD <<" | "<<m_QA<<" | "<<m_QB<<" | "<<m_QC<<endl;
}
