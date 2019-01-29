SC_MODULE(andgate){
	//ports
	sc_in<bool> in1, in2;
	sc_out<bool> out;

	//constructor
	SC_CTOR(andgate){
		SC_METHOD(andproc);
		sensitive<<in1<<in2;
		dont_initialize();
	}
	void andproc(void){
		out=in1&&in2;
	}
};
