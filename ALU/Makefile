#GTKWAVE:=$(shell which gtkwave)

all: alu

alu:#prerequisites
	@echo 'building file $(@F)'
	$(CXX) -I/usr/local/systemc-2.3.2/include -O0 -g3 -Wall -c ALU.cpp

	$(CXX) -L/usr/local/systemc-2.3.2/lib-linux64 -o "alu" ALU.o -lsystemc
	./alu
	gtkwave -c 4 vcd_trace.vcd

#prerequisites:
#ifdef $(GTKWAVE)
#	@echo "running gtkwave"
#else
#	@echo 'installing gtkwave, please be patient'
#	sudo apt-get install -y gtkwave
#endif

clean:
	rm -f alu *.o vcd_trace.vcd
.PHONY: alu
