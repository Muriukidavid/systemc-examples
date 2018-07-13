#include "monitor.h"
#include<iostream>

using namespace std;

void monitor::mon(void){
	cout<<"at "<<sc_time_stamp()<<" input is: "<<m_din<<" output are: "<<m_dout<<","<<m_do1<<","<<m_do2<<"and"<<m_do3<<endl;
}
