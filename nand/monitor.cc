#include "monitor.h"
#include<iostream>

using namespace std;

void monitor::monita(void){
	cout<<"at "<<sc_time_stamp()<<" input is: "<<m_A<<" and "<<m_B<<", output is: | "<<m_out<<" | "<<endl;
}
