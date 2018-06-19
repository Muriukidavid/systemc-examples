GTKWAVE:=$(which gtkwave)

all: dflipflop

dflipflop:prerequisites
	@echo 'building file $(@F)'
	$(CXX) -I/usr/local/systemc-2.3.2/include -O0 -g3 -Wall -c driver.cc
	$(CXX) -I/usr/local/systemc-2.3.2/include -O0 -g3 -Wall -c dff.cc
	$(CXX) -I/usr/local/systemc-2.3.2/include -O0 -g3 -Wall -c monitor.cc
	$(CXX) -I/usr/local/systemc-2.3.2/include -O0 -g3 -Wall -c main.cpp
	$(CXX) -L/usr/local/systemc-2.3.2/lib-linux64 -o "dflipflop" main.o monitor.o dff.o driver.o -lsystemc
	./dflipflop
	gtkwave -c 4 vcd_trace.vcd

prerequisites: 
ifeq "$(GTKWAVE)" "/usr/bin/gtkwave"
	@echo 'installing gtkwave, please be patient'
	sudo apt-get install -y gtkwave
endif

clean:
	rm -f dflipflop *.o vcd_trace.vcd
.PHONY: dflipflop
