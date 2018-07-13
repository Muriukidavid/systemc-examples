#include "iomanip"

SC_MODULE(mon) {     
	sc_in<bool> zero;
	sc_in < sc_uint<8> > opA,opB,result;
	sc_in < sc_uint<4> > op;
	sc_in <bool> Clk;
	void monitor()   {     
		cout << std::setw(11) << "Time";     
		cout << std::setw(10) << "opA";     
		cout << std::setw(10) << "opB";     
		cout << std::setw(10) << "op";     
		cout << std::setw(10) << "result"; 
		cout << std::setw(5) << "zero" << endl ;
		int i=0;
		while(true){
			wait();
			cout << i;
			i++;
			cout << std::setw(10) << sc_time_stamp();
			cout << std::setw(10) << opA;       
			cout << std::setw(10) << opB;   
			cout << std::setw(10) << op;           
			cout << std::setw(10) << result;
			cout << std::setw(5) << zero.read() << endl;
		}
	}

	SC_CTOR(mon)   {     
		SC_THREAD(monitor);
			sensitive << Clk.pos() ;
	} 
};
