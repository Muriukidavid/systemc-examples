GTKWAVE:=$(which gtkwave)

all: dff

dff:prerequisites
	@echo 'building file $(@F)'
	$(CXX) -I/usr/local/systemc-2.3.2/include -O0 -g3 -Wall -c main.cpp
	$(CXX) -L/usr/local/systemc-2.3.2/lib-linux64 -o "D-flipflop" main.o -lsystemc
	./dff
	gtkwave -c 4 vcd_trace.vcd

prerequisites: 
ifneq "$(GTKWAVE)" "/usr/bin/gtkwave"
#	@echo 'installing gtkwave, please be patient'
#	sudo apt-get install -y gtkwave
endif 

clean:
	rm -f dff *.o timing_diagram.vcd
.PHONY: dff
