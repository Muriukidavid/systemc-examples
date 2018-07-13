GTKWAVE:= which gtkwave

all: clean shift 

shift:
	@echo 'building file $(@F)'
	$(CXX) -I/usr/local/systemc-2.3.2/include -O0 -g3 -Wall -c dff.cc driver.cc monitor.cc nand.cc shiftreg.cc notgate.cc main.cpp
	$(CXX) -L/usr/local/systemc-2.3.2/lib-linux64 -o "shift" dff.o driver.o monitor.o nand.o notgate.o main.o shiftreg.o  -lsystemc
	./shift
	gtkwave -c 4 vcd_trace.vcd

prerequisites: 
ifneq ('$(GTKWAVE)', "/usr/bin/gtkwave")
	@echo $(GTKWAVE)
	@echo 'installing gtkwave, please be patient'
	sudo apt-get install -y gtkwave
endif

clean:
	rm -f shift *.o vcd_trace.vcd
.PHONY: shift
