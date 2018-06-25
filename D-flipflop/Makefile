GTKWAVE:=$(which gtkwave)

all: Dflipflop

Dflipflop:#prerequisites
	@echo 'building file $(@F)'
	$(CXX) -I/usr/local/systemc-2.3.2/include -O0 -g3 -Wall -c dff.cc driver.cc main.cpp monitor.cc 
	$(CXX) -L/usr/local/systemc-2.3.2/lib-linux64 -o "dff" dff.o driver.o monitor.o main.o -lsystemc
	./dff
	gtkwave -c 4 vcd_trace.vcd

#prerequisites: 
#ifneq "$(GTKWAVE)" "/usr/bin/gtkwave"
#	@echo 'installing gtkwave, please be patient'n.cpp 
#	sudo apt-get install -y gtkwave
#endif

clean:
	rm -f dff *.o vcd_trace.vcd
.PHONY: Dflipflop
