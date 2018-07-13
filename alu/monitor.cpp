#include "monitor.h"

void monitor::monita(){
		cout << setw(11) << "Time";     
		cout << setw(10) << "operand1";     
		cout << setw(10) << "operand2";     
		cout << setw(10) << "opcode";     
		cout << setw(10) << "result"; 
		cout << setw(5) << "zero" << endl ;
		int i=0;
		while(true){
			wait();
			cout << i;
			i++;
			cout << setw(10) << sc_time_stamp();
			cout << setw(10) << operand1;       
			cout << setw(10) << operand2;   
			cout << setw(10) << opcode;           
			cout << setw(10) << result;
			cout << setw(5) << zero.read() << endl;
		}	
}
