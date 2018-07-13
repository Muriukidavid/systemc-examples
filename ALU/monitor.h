#include "iomanip"

SC_MODULE(mon) {     
	sc_in<bool> zero,carry;
	sc_in < sc_uint<4> > opA,opB,result;
	sc_in < sc_uint<3> > op;
	sc_in <bool> clk;

	void monitor(){     
		cout << std::setw(11) << "Time";     
		cout << std::setw(10) << "opA";     
		cout << std::setw(10) << "opB";     
		cout << std::setw(10) << "op";     
		cout << std::setw(10) << "result"; 
		cout << std::setw(15) << "carry/borrow";		
		cout << std::setw(10) << "zero"<<endl ;
		while(true){
			wait();
			cout << std::setw(10) << sc_time_stamp();
			cout << std::setw(10) << opA;       
			cout << std::setw(10) << opB;   
			cout << std::setw(10) << op;           
			cout << std::setw(10) << result;
			cout << std::setw(15) << carry;
			cout << std::setw(10) << zero.read()<<endl;
		
	}
}

	SC_CTOR(mon){     
		SC_THREAD(monitor);
			sensitive << clk.pos() ;
	}
};
