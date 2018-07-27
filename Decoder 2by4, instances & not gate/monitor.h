
#ifndef MONITOR_H_
#define MONITOR_H_
#include<iostream>
#include<systemc>

using namespace std;

SC_MODULE(monitor){
sc_in<bool> m1, m2, m3, m4, m5, m6;

SC_CTOR(monitor){
	SC_METHOD(monita);
	dont_initialize();
}


void monita(void){
		cout<<"at "<<sc_time_stamp()<<" 1st_binary_input: "<<m1<<" 2nd_binary_input: "<<m2<<" d_out1: "<<m3<<" d_out2 "<<m4<<"  d_out3 "<<m5<<" d_out4 "<<m6<<endl;
	}
};
#endif /* MONITOR_H_ */

