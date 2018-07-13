all: alu

alu:
	@echo 'building file $(@F)'
	$(CXX) -I/usr/local/systemc-2.3.2/include -O0 -g3 -Wall -c main.cpp monitor.cpp operations.cpp driver.cpp
	$(CXX) -L/usr/local/systemc-2.3.2/lib-linux64 -o "alu" main.o monitor.o operations.o driver.o -lsystemc
	./alu

clean:
	rm -f alu *.o 
.PHONY: alu
