#include<systemc>
#include<iostream>
#include "monitor.h"

using namespace std;

void monitor::mon(void){
	cout<<"at "<<sc_time_stamp()<<" input is: "<<m_din<<" output is: "<<m_dout<<endl;
}
