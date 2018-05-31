# Makefile
# Created on: Nov 14, 2016
#      Author: Your's Trully

GTKWAVE := $(shell which gtkwave)
APP := decoder

all: decoder

decoder: prerequisites
	@echo 'building file $(@F)'
	$(CXX) -I/usr/local/systemc-2.3.2/include -O0 -g3 -Wall -c decoder_2by4.cpp
	$(CXX) -L/usr/local/systemc-2.3.2/lib-linux64 -o "$(APP)" decoder_2by4.o -lsystemc
	./$(APP) 30
	gtkwave -c 4 timing_diagram.vcd

prerequisites: 
ifneq "$(GTKWAVE)" "/usr/bin/gtkwave"
	@echo $(GTKWAVE)	
	@echo 'installing gtkwave, please be patient'
	sudo apt-get install -y gtkwave
endif

clean:
	rm $(APP) *.o *.vcd
.PHONY: decoder

















