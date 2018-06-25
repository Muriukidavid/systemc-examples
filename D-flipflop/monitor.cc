<<<<<<< HEAD
#include "monitor.h"
#include<iostream>

using namespace std;

void monitor::mon(void){
	cout<<"at "<<sc_time_stamp()<<" input is: "<<m_din<<" output is: "<<m_dout<<endl;
}
||||||| merged common ancestors
=======
#include "monitor.h"
#include<iostream>

using namespace std;

void monitor::mon(void){
	cout<<"at "<<sc_timestamp()<<" input is: "m_din<<" output is: "<<m_dout<<endl;
}
>>>>>>> bf9f72666fbec1eeb586f1f72fdaff7fdf95539f
