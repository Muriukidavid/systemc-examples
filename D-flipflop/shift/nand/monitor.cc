#include "monitor.h"
#include<iostream>

using namespace std;

void monitor::mon(void){
	cout<<"at "<<sc_time_stamp()<<" inputs are: "<<m_A<<" "<<m_B<<" output is: "<<m_F<<endl;
}
