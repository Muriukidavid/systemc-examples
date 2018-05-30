This is a 2-by-4 decoder example, which is a makefile project and so no need for an IDE. 
Just cd into this folder and run the command 

    make decoder


A line decoder is a device that changes the input code into a set of signals.<br>
It takes an n-digit binary number and decodes it into 2<sup>n</sup> data lines.
It does the reverse of encoding. <br>
In the following is a 2by4 decoder truth table. <br>
Its truth table: 
<p align="left">
  <img src="images/truth_table.png" width="250"/>
</p>

###Circuit:
<p align="left">
  <img src="images/circuit.gif" width="200"/>
</p>

Model of computation:
<p align="left">
  <img src="images/MoC.png" width="400"/>
</p>
Results:
The above MOC was implemented in systemc (code in this folder) and the following output found from traced signals.<br>
Traced signals timing diagram:
<p align="left">
  <img src="images/timing_diagram.png" width="400"/>
<p>
RESULTS:
 The above MOC was implemented in systemc (code in this folder) and the following output found from traced signals.<br>
 Traced signals timing diagram:
