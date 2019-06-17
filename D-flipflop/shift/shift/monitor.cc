#include "monitor.h"
#include<iostream>

using namespace std;

void monitor::mon(void){
	cout<<"at "<<sc_time_stamp()<<" input is: "<<m_din<<" output is: "<<m_QA <<"and"<<m_QB<<"and"<<m_QC<<"and"<<m_QD<<endl;
}
