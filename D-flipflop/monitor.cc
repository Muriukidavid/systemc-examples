#include "monitor.h"
#include<iostream>

using namespace std;

void monitor::mon(void){
	cout<<"at "<<sc_timestamp()<<" input is: "m_din<<" output is: "<<m_dout<<endl;
}
