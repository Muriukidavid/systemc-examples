GTKWAVE:=$(which gtkwave)
all: sr

sr:
	@echo 'building file $(@F)'
	$(CXX) -I/usr/local/systemc-2.3.2/include -O0 -g3 -Wall -c dff.cc driver.cc monitor.cc NAND.cc main.cpp shiftR.cc
	$(CXX) -L/usr/local/systemc-2.3.2/lib-linux64 -o "sr" dff.o driver.o monitor.o NAND.o main.o shiftR.o -lsystemc
	./sr
	gtkwave -c 4 vcd_trace.vcd

	
prerequisites: 
ifneq  ('$(GTKWAVE)', "/usr/bin/gtkwave")
	@echo 'installing gtkwave, please be patient'
	apt-get install -y gtkwave
endif


clean:
	rm -f sr *.o vcd_trace.vcd
.PHONY: sr
