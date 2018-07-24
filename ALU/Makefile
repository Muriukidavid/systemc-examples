GTKWAVE:=$(which gtkwave)

all: ALU

ALU:#prerequisites
	@echo 'building file $(@F)'
	$(CXX) -I/usr/local/systemc-2.3.2/include -O0 -g3 -Wall -c ALU.cc driver.cc main.cpp
	$(CXX) -L/usr/local/systemc-2.3.2/lib-linux64 -o "ALU" ALU.o driver.o main.o -lsystemc
	./ALU
	gtkwave -c 4 vcd_trace.vcd

#prerequisites: 
#ifneq "$(GTKWAVE)" "/usr/bin/gtkwave"
#	@echo 'installing gtkwave, please be patient'n.cpp 
#	sudo apt-get install -y gtkwave
#endif

clean:
	rm -f ALU *.o vcd_trace.vcd
.PHONY: ALU
