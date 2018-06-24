#include "monitor.h"
#include<iostream>

using namespace std;

void monitor::mon(void){
	cout<<"at "<<sc_time_stamp()<<" input is: "<<m_din<<" output is: "<<m_dff1dff2<< "  " <<m_dff2dff3<< "  " <<m_dff3dff4<< "  " <<m_dout<<endl;
}
