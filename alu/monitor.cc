#include<systemc>
#include<iostream>
#include "monitor.h"

using namespace std;

void monitor::mon()   {
		cout << "Time";
		cout << "OP-A";
		cout << "OP-B";
		cout << "OP Code";
		cout << "Carry/Borrow";
		cout << "Result";
		cout << endl ;
		int i=0;
		while(true){
			wait();
			cout << i;
			i++;
			cout << sc_time_stamp();
			cout << opA;
			cout << opB;
			cout << op;
			cout << op;
			cout << carry;
			cout << zero.read() << endl;
		}
	}
