This is a 2-by-4 decoder example, which is a makefile project and so no need for an IDE. 
Just cd into this folder and run the command 

    make 


A line decoder is a device that changes the input code into a set of signals.<br>
It takes an n-digit binary number and decodes it into 2<sup>n</sup> data lines.
It does the reverse of encoding. <br>
In the following truth table, only the output D0 is high when the both inputs zero, the output D1 is high when the the first input is zero and the second input is 1, the output D2 is high when input A0 is 1 and A1 is one and the output D3  is high when both inputs are high. it decodes a two digit binary number.
Only one signal is high(selected) when the right binary number is available on the input. <br>
Its truth table: 
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
The above MOC was implemented in systemc (code in this folder) and the following output found from traced signals.<br>
Traced signals timing diagram:
<p align="left">
  <img src="IMAGES/timing_diagram.png" width="400"/>
<p>


