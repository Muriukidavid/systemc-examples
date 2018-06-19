This is a 1-by-2 decoder example, which is a makefile project and so no need for an IDE. 
Just cd into this folder and run the command 

    make decoder


A line decoder is a device that changes the input code into a set of signals.<br>
It takes an n-digit binary number and decodes it into 2<sup>n</sup> data lines.
It does the reverse of encoding. <br>
In the following truth table, only the output D0 is high when the input is zero, and the output D1 is high when the input is 1. it decodes a single digit binary number.
Only one signal is high(selected) when the right binary number is available on the input. <br>
Its truth table: 
<p align="left">
  <img src="images/truth_table.png" width="250"/>
</p>

### Circuit:
<p align="left">
  <img src="images/circuit.gif" width="200"/>
</p>

### Model of computation:
<p align="left">
  <img src="images/MoC.png" width="400"/>
</p>

### Results:
The above MOC was implemented in systemc (code in this folder) and the following output found from traced signals.<br>
Traced signals timing diagram:
<p align="left">
  <img src="images/timing_diagram.png" width="400"/>
<p>

### Tutorial 1:
Create a decoder_2by4 based on this decoder_1by2.<br>
Reuse the systemc module for decoder_1by2 cascaded to build a more complex module for the decoder_2by4.
<em>Hint:</em> use additional and logic (AND) gates to determine the final outputs as in the truth table.
