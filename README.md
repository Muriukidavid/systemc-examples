Implementation of a 2-by-4 decoder. Decoder1by2 is included in the .cpp file with the main function. Two instances are created. In decoder 1by2 an inveter is used and a notgate.h is created containg the implementation of the not-gate module. There is no need for an IDE in this project.

just navigate into this folder and run the command 

 
make

A line decoder changes the input code into a set of signals.<br>
It usually takes an n-digit binary decoding it into 2<sup>n</sup> data lines.
It be can used to extract encoded information  <br>
In the next truth table, the output D0 is high when the both inputs are 0, the output D1 is high when the the first input is 0 and the second input is 1, the output D2 is high when input A0 is 1 and A1 is 1. The output D3  is high when both inputs are high. 
Only one signal is high when the right binary number is available on the input. <br>
Truth table: 
<p align="left">
  <img src="IMAGES/truth_table.jpg" width="250"/>
</p>

###Circuit:
<p align="left">
  <img src="IMAGES/circuit.jpg" width="200"/>
</p>

Model of computation:
<p align="left">
  <img src="images/MoC.png" width="400"/>
</p>
Results:
The above MOC was implemented in systemc and the following output generated from traced signals.<br>
Traced signals timing diagram:
<p align="left">
  <img src="IMAGES/timing_diagram.png" width="400"/>
<p>


