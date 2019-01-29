#include "monitor.h"
#include<iostream>

using namespace std;

void monitor::monita(void){
	cout<<"at "<<sc_time_stamp()<<" OPCODE is:"<<m_OPCODE<<" inputs are: | "<<m_OP1 <<" | "<<m_OP2<<" outputs are: | ";
	cout<<m_CARRY<<" | "<<m_ZERO<<" | "<<m_RESULT<<endl;//<<" input is: "<<m_din
}
