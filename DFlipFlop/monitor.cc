#include "monitor.h"
#include<iostream>

using namespace std;

void monitor::monita(void){
	cout<<"at "<<sc_time_stamp()<<" clear is:"<<m_clr<<" output is: | "<<m_dout <<" | "<<endl;//<<" input is: "<<m_din
}
