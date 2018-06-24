GTKWAVE:=$(shell which gtkwave)

all: dff

dff:
	@echo 'building file $(@F)'
	$(CXX) -I/usr/local/systemc-2.3.2/include -O0 -g3 -Wall -c dff.cc driver.cc monitor.cc NAND.cc main.cpp 
	$(CXX) -L/usr/local/systemc-2.3.2/lib-linux64 -o "dff" dff.o driver.o monitor.o NAND.o main.o -lsystemc
	./dff
	gtkwave -c 4 vcd_trace.vcd

clean:
	rm -f dff *.o vcd_trace.vcd
.PHONY: dff
