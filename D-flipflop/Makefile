GTKWAVE:= which gtkwave

all: dff

dff:prerequisites
	@echo 'building file $(@F)'
	$(CXX) -I/usr/local/systemc-2.3.2/include -O0 -g3 -Wall -c dff.cc driver.cc monitor.cc main.cpp
	$(CXX) -L/usr/local/systemc-2.3.2/lib-linux64 -o "dff" dff.o driver.o monitor.o main.o -lsystemc
	./dff
	gtkwave -c 4 vcd_trace.vcd

prerequisites: 
ifneq ('$(GTKWAVE)', "/usr/bin/gtkwave")
	@echo $(GTKWAVE)
	@echo 'installing gtkwave, please be patient'
	sudo apt-get install -y gtkwave
endif

clean:
	rm -f dff *.o vcd_trace.vcd
.PHONY: dff
